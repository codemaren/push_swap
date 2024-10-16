/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:17:28 by kilangov          #+#    #+#             */
/*   Updated: 2024/10/12 16:17:32 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	max_bits;
	int	max_pos;

	max_bits = 0;
	max_pos = size;
	while (max_pos > 0)
	{
		max_bits++;
		max_pos >>= 1;
	}
	return (max_bits);
}

static void	radix_sort_iteration(t_stack *a, t_stack *b, int bit)
{
	int	size;
	int	i;

	size = a->size;
	i = 0;
	while (i < size)
	{
		if ((a->top->position & (1 << bit)) == 0)
			pb(a, b);
		else
			ra(a);
		i++;
	}
	while (b->size > 0)
		pa(a, b);
}

int	sort_medium(t_stack *a, t_stack *b, int size)
{
	int	max_bits;
	int	current_bit;

	max_bits = get_max_bits(size);
	current_bit = 0;
	while (current_bit < max_bits)
	{
		radix_sort_iteration(a, b, current_bit);
		current_bit++;
	}
	return (1);
}
