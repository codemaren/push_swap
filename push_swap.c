/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:54:29 by kilangov          #+#    #+#             */
/*   Updated: 2024/09/15 18:55:22 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	print_error(void)
{
	int	write_return;

	write_return = write(2, "Error\n", 6);
	return (write_return);
}

static t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return (stack);
}

static void	free_stack(t_stack **stack)
{
	t_dlist	*current;
	t_dlist	*next;

	if (!stack || !*stack)
		return ;
	current = (*stack)->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(*stack);
	*stack = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		sort_result;

	if (argc < 2)
		return (0);
	stack_a = init_stack();
	stack_b = init_stack();
	if (!stack_a || !stack_b)
		return (free_stack(&stack_a), free_stack(&stack_b), print_error(), 1);
	if (!process_input(argc, argv, stack_a))
		return (free_stack(&stack_a), free_stack(&stack_b), print_error(), 1);
	normalise_stack(stack_a);
	sort_result = sort_stack(stack_a, stack_b);
	if (!sort_result)
		return (free_stack(&stack_a), free_stack(&stack_b), 1);
	return (free_stack(&stack_a), free_stack(&stack_b), 0);
}
