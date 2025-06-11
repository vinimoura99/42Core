/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:10:41 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/11 14:42:38 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					rank;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}						t_stack_node;

typedef struct s_stack
{
	t_stack_node		*top;
	t_stack_node		*bottom;
	int					size;
}						t_stack;

t_stack_node			*new_node(int value);

// Error
void					exit_error(void);

// String_utils
void					ft_putstr(const char *s);
void					ft_putendl(const char *s);
void					ft_putnbr(int n);

// Op_push
void					pa(t_stack *stack_a, t_stack *stack_b);
void					pb(t_stack *stack_a, t_stack *stack_b);

// Op_rev_rot
void					rra(t_stack *stack_a, int print_op);
void					rrb(t_stack *stack_b, int print_op);
void					rrr(t_stack *stack_a, t_stack *stack_b);

// Op_rot
void					ra(t_stack *stack_a, int print_op);
void					rb(t_stack *stack_b, int print_op);
void					rr(t_stack *stack_a, t_stack *stack_b);

// Op_swap
void					sa(t_stack *stack_a, int print_op);
void					sb(t_stack *stack_b, int print_op);
void					ss(t_stack *stack_a, t_stack *stack_b);

// Sort_radix
void					sort_radix(t_stack *a, t_stack *b);

// Sort_small
int						sort_small_stack(t_stack *a, t_stack *b);

// Input_utils
int						is_number_str(const char *str);
long					ft_atol(const char *str);

// Parser_utils
void					print_stack(t_stack *stack, const char *name);
void					free_split(char **split);
void					parse_args(char **args, t_stack *stack_a,
							int should_free);
int						has_duplicate(t_stack *stack_a, int value);
void					free_resources(t_stack *stack_a, t_stack *stack_b,
							char **args, int should_free);

// Sort_utils
int						find_pos(t_stack *stack, int target_rank);
void					rotate_to_top(t_stack *a, int pos, int size);
void					bring_to_top_a(t_stack *a, int target_rank);
void					exec_case(int r0, int r1, int r2, t_stack *a);

// Common_utils
int						is_sorted(t_stack *stack);
char					**ft_split(const char *s, char c);

// String_utils
void					ft_putstr(const char *s);
void					ft_putendl(const char *s);
void					ft_putnbr(int n);
void					free_stack(t_stack *stack);
t_stack_node			*new_node(int value);

// Stack_utils
void					stack_init(t_stack *stack);
void					push_node_to_top(t_stack *stack, t_stack_node *node);
void					push_value_to_top(t_stack *stack, int value);
void					add_node_to_bottom(t_stack *stack, t_stack_node *node);
void					add_value_to_bottom(t_stack *stack, int value);

// Assign_rank
void					assign_ranks(t_stack *stack);
#endif