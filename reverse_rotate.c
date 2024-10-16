/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:17:53 by kilangov          #+#    #+#             */
/*   Updated: 2024/10/12 16:17:55 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate_stack(t_stack *stack)
{
	t_dlist	*last;

	if (!stack || !stack->top || !stack->top->next || stack->size < 2)
		return (0);
	last = stack->bottom;
	stack->bottom = last->prev;
	stack->bottom->next = NULL;
	last->prev = NULL;
	last->next = stack->top;
	stack->top->prev = last;
	stack->top = last;
	return (1);
}

int	rra(t_stack *stack_a)
{
	if (reverse_rotate_stack(stack_a))
		return (write(1, "rra\n", 4) == 4);
	return (0);
}

int	rrb(t_stack *stack_b)
{
	if (reverse_rotate_stack(stack_b))
		return (write(1, "rrb\n", 4) == 4);
	return (0);
}

int	rrr(t_stack *stack_a, t_stack *stack_b)
{
	int	a_success;
	int	b_success;

	a_success = reverse_rotate_stack(stack_a);
	b_success = reverse_rotate_stack(stack_b);
	if (a_success && b_success)
		return (write(1, "rrr\n", 4) == 4);
	if (a_success)
		rotate_stack(stack_a);
	if (b_success)
		rotate_stack(stack_b);
	return (0);
}
