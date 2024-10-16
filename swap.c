/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:17:07 by kilangov          #+#    #+#             */
/*   Updated: 2024/10/12 16:17:11 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_stack(t_stack *stack)
{
	t_dlist	*first;
	t_dlist	*second;

	if (!stack || !stack->top || !stack->top->next || stack->size < 2)
		return (0);
	first = stack->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->top = second;
	if (stack->size == 2)
		stack->bottom = first;
	return (1);
}

int	sa(t_stack *stack_a)
{
	if (swap_stack(stack_a))
		return (write(1, "sa\n", 3) == 3);
	return (0);
}

int	sb(t_stack *stack_b)
{
	if (swap_stack(stack_b))
		return (write(1, "sb\n", 3) == 3);
	return (0);
}

int	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	a_success;
	int	b_success;

	a_success = swap_stack(stack_a);
	b_success = swap_stack(stack_b);
	if (a_success && b_success)
		return (write(1, "ss\n", 3) == 3);
	if (a_success)
		swap_stack(stack_a);
	if (b_success)
		swap_stack(stack_b);
	return (0);
}
