#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h> // For size_t
# include <limits.h> // For INT_MAX, INT_MIN
# include <stdlib.h> // For NULL, malloc, free
# include <unistd.h> // For write (used in operations)

// --- Structure Definitions FIRST ---

// Structure for a stack node
typedef struct s_stack_node
{
    int					value;
    int					rank;
    struct s_stack_node	*prev;
    struct s_stack_node	*next;
}	t_stack_node;

// Structure for the stack itself
typedef struct s_stack
{
    t_stack_node	*top;
    t_stack_node	*bottom;
    int				size;
}	t_stack;

// --- Function Prototypes AFTER Structure Definitions ---

// Stack utilities
t_stack_node	*new_node(int value);
void			stack_init(t_stack *stack);
// void			push_to_stack(t_stack *stack, int value); // Original, maybe remove if not used
void            push_node_to_top(t_stack *stack, t_stack_node *node); // If used by operations
void            push_value_to_top(t_stack *stack, int value); // If used
void			free_stack(t_stack *stack);
void			add_node_to_bottom(t_stack *stack, t_stack_node *node);
void			add_value_to_bottom(t_stack *stack, int value);

// Ranking function
void			assign_ranks(t_stack *stack);

// --- Sorting Utilities ---  <--- NEW SECTION (or add to existing utils)
int				is_sorted(t_stack *stack); // <--- ADD THIS PROTOTYPE

// --- Stack Operations ---
void	sa(t_stack *stack_a, int print_op);
void	sb(t_stack *stack_b, int print_op);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a, int print_op);
void	rb(t_stack *stack_b, int print_op);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a, int print_op);
void	rrb(t_stack *stack_b, int print_op);
void	rrr(t_stack *stack_a, t_stack *stack_b);

// --- Sorting Algorithms ---
int		sort_small_stack(t_stack *stack_a, t_stack *stack_b); // MODIFIED

void	sort_radix(t_stack *stack_a, t_stack *stack_b); // <--- ADD THIS LINE

// Other utilities
void	exit_error(void);
int		is_number_str(const char *str);
long	ft_atol(const char *str);

#endif