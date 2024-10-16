/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:16:46 by kilangov          #+#    #+#             */
/*   Updated: 2024/10/12 16:18:20 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*Push from B to A*/
int	pa(t_stack *a, t_stack *b)
{
	t_pop	popped;

	if (!a || !b)
		return (0);
	if (b->size == 0)
		return (1);
	popped = pop(b);
	if (!push(a, popped.value, popped.position))
	{
		if (!push(b, popped.value, popped.position))
		{
			if (write(2, "Error\n", 6) == 6)
				return (0);
			return (0);
		}
	}
	return (write(1, "pa\n", 3) == 3);
}

/*Push from A to B*/
int	pb(t_stack *a, t_stack *b)
{
	t_pop	popped;

	if (!a || !b)
		return (0);
	if (a->size == 0)
		return (1);
	popped = pop(a);
	if (!push(b, popped.value, popped.position))
	{
		if (!push(a, popped.value, popped.position))
		{
			if (write(2, "Error\n", 6) == 6)
				return (0);
			return (0);
		}
	}
	return (write(1, "pb\n", 3) == 3);
}
