/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:17:44 by kilangov          #+#    #+#             */
/*   Updated: 2024/10/12 16:17:46 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_stack(t_stack *stack)
{
	t_dlist	*first;

	if (!stack || !stack->top || !stack->top->next || stack->size < 2)
		return (0);
	first = stack->top;
	stack->top = first->next;
	stack->top->prev = NULL;
	stack->bottom->next = first;
	first->prev = stack->bottom;
	first->next = NULL;
	stack->bottom = first;
	return (1);
}

int	ra(t_stack *stack_a)
{
	if (rotate_stack(stack_a))
		return (write(1, "ra\n", 3) == 3);
	return (0);
}

int	rb(t_stack *stack_b)
{
	if (rotate_stack(stack_b))
		return (write(1, "rb\n", 3) == 3);
	return (0);
}

int	rr(t_stack *stack_a, t_stack *stack_b)
{
	int	a_success;
	int	b_success;

	a_success = rotate_stack(stack_a);
	b_success = rotate_stack(stack_b);
	if (a_success && b_success)
		return (write(1, "rr\n", 3) == 3);
	if (a_success)
		reverse_rotate_stack(stack_a);
	if (b_success)
		reverse_rotate_stack(stack_b);
	return (0);
}
