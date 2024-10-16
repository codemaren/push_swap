/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:17:15 by kilangov          #+#    #+#             */
/*   Updated: 2024/10/12 16:17:17 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Allocate new node, and assign value.*/
int	push(t_stack *stack, int value, int position)
{
	t_dlist	*new_node;

	new_node = ft_dlstnew(value, position);
	if (!new_node)
		return (0);
	if (!stack->top)
	{
		stack->top = new_node;
		stack->bottom = new_node;
	}
	else
	{
		new_node->next = stack->top;
		stack->top->prev = new_node;
		stack->top = new_node;
	}
	stack->size++;
	return (1);
}

/* Re-assign stack->top to stack->top->next, free top node 
   and return its content */
t_pop	pop(t_stack *stack)
{
	t_dlist			*temp;
	t_pop			result;

	result.value = -1;
	result.position = -1;
	if (!stack->top)
		return (result);
	temp = stack->top;
	result.value = temp->content;
	result.position = temp->position;
	stack->top = temp->next;
	if (stack->top)
		stack->top->prev = NULL;
	else
		stack->bottom = NULL;
	free(temp);
	stack->size--;
	return (result);
}

int	push_init(t_stack *stack, int value)
{
	t_dlist	*new_node;
	int		position;

	position = 0;
	new_node = ft_dlstnew(value, position);
	if (!new_node)
		return (0);
	ft_dlstadd_back(&(stack->top), new_node);
	stack->bottom = new_node;
	stack->size++;
	return (1);
}

t_dlist	*ft_dlstnew(int content, int position)
{
	t_dlist	*new;

	new = (t_dlist *)malloc(sizeof(t_dlist));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	new->position = position;
	return (new);
}

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}
