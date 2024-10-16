/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:16:34 by kilangov          #+#    #+#             */
/*   Updated: 2024/10/12 16:16:37 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	is_valid_input(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	check_duplicates(t_stack *stack, int value)
{
	t_dlist	*current;

	current = stack->top;
	while (current)
	{
		if (current->content == value)
			return (0);
		current = current->next;
	}
	return (1);
}

static int	process_number(char *str, t_stack *stack)
{
	long	num;

	if (!is_valid_input(str))
		return (0);
	num = ft_atol(str);
	if (num == 2147483648)
		return (0);
	if (!check_duplicates(stack, (int)num))
		return (0);
	if (!push_init(stack, (int)num))
		return (0);
	return (1);
}

int	process_input(int argc, char **argv, t_stack *stack)
{
	int		i;
	char	**split;
	int		j;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (0);
		j = 0;
		while (split[j])
		{
			if (!process_number(split[j], stack))
				return (free_split(split), 0);
			j++;
		}
		free_split(split);
		i++;
	}
	return (1);
}
