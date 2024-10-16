/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:48:41 by kilangov          #+#    #+#             */
/*   Updated: 2024/09/14 21:57:33 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "./libft/libft.h"

typedef struct s_dlist
{
	int				content;
	int				position;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

typedef struct s_stack
{
	t_dlist	*top;
	t_dlist	*bottom;
	int		size;
}	t_stack;

typedef struct s_pop
{
	int		value;
	int		position;
}t_pop;

// Libft function prototypes
long	ft_atol(const char *nptr);
char	**ft_split(char const *s, char c);
t_dlist	*ft_dlstnew(int content, int position);
void	ft_dlstadd_back(t_dlist **lst, t_dlist *new);

// Error handling
int		is_valid_input(char *str);

// Stack operations
int		push_init(t_stack *stack, int value);
int		push(t_stack *stack, int value, int position);
int		rotate_stack(t_stack *stack);
int		reverse_rotate_stack(t_stack *stack);
t_pop	pop(t_stack *stack);

// Input processing		
int		process_input(int argc, char **argv, t_stack *stack);

// Push swap operations
int		pa(t_stack *a, t_stack *b);
int		pb(t_stack *a, t_stack *b);
int		rra(t_stack *stack_a);
int		rrb(t_stack *stack_b);
int		rrr(t_stack *stack_a, t_stack *stack_b);
int		ra(t_stack *stack_a);
int		rb(t_stack *stack_b);
int		rr(t_stack *stack_a, t_stack *stack_b);
int		sa(t_stack *stack_a);
int		sb(t_stack *stack_b);
int		ss(t_stack *stack_a, t_stack *stack_b);

// Sort Operations
int		is_sorted_ascending(t_stack *stack);
int		is_sorted_descending(t_stack *stack);
void	normalise_stack(t_stack *stack);
int		sort_stack(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
int		sort_small(t_stack *a, t_stack *b, int size);
int		sort_medium(t_stack *a, t_stack *b, int size);

#endif
