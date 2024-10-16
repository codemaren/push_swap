/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:17:00 by kilangov          #+#    #+#             */
/*   Updated: 2024/10/12 16:17:03 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_ascending(t_stack *stack)
{
	t_dlist	*current;

	if (!stack->top || !stack->top->next)
		return (0);
	current = stack->top;
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

int	is_sorted_descending(t_stack *stack)
{
	t_dlist	*current;

	if (!stack->top || !stack->top->next)
		return (0);
	current = stack->top;
	while (current->next)
	{
		if (current->content < current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	normalise_stack(t_stack *stack)
{
	t_dlist	*current;
	t_dlist	*compare;
	int		position;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	while (current)
	{
		position = 1;
		compare = stack->top;
		while (compare)
		{
			if (current->content > compare->content)
				position++;
			compare = compare->next;
		}
		current->position = position;
		current = current->next;
	}
}
