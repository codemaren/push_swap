/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:17:36 by kilangov          #+#    #+#             */
/*   Updated: 2024/10/12 16:17:39 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->position;
	second = a->top->next->position;
	third = a->bottom->position;
	if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first > second && second < third && first < third)
		sa(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

static t_dlist	*find_smallest(t_stack *a)
{
	t_dlist	*current;
	t_dlist	*smallest;

	current = a->top;
	smallest = current;
	while (current)
	{
		if (current->position < smallest->position)
			smallest = current;
		current = current->next;
	}
	return (smallest);
}

static int	move_smallest_to_b(t_stack *a, t_stack *b)
{
	t_dlist	*smallest;
	t_dlist	*current;
	int		i;

	smallest = find_smallest(a);
	i = 1;
	current = a->top;
	while (current != smallest)
	{
		i++;
		current = current->next;
	}
	while (a->top != smallest)
	{
		if (i <= a->size / 2)
			ra(a);
		else
			rra(a);
	}
	return (pb(a, b));
}

int	sort_small(t_stack *a, t_stack *b, int size)
{
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else
	{
		while (size > 3)
		{
			if (!move_smallest_to_b(a, b))
				return (0);
			size--;
		}
		sort_three(a);
		while (b->size)
		{
			if (!pa(a, b))
				return (0);
		}
	}
	return (1);
}

int	sort_stack(t_stack *a, t_stack *b)
{
	int	size;

	if (is_sorted_ascending(a))
		return (1);
	size = a->size;
	if (size == 1)
		return (1);
	if (size <= 20)
		return (sort_small(a, b, size));
	else
		return (sort_medium(a, b, size));
}
