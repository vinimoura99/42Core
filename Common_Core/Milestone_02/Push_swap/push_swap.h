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

// Stack_init
t_stack_node	*new_node(int value);
void			stack_init(t_stack *stack);

//Stack_free
void free_stack(t_stack *stack);

//Stack_push
void push_node_to_top(t_stack *stack, t_stack_node *node);
void push_value_to_top(t_stack *stack, int value);
void add_node_to_bottom(t_stack *stack, t_stack_node *node);
void add_value_to_bottom(t_stack *stack, int value);

// void			push_to_stack(t_stack *stack, int value); // Original, maybe remove if not used
void            push_node_to_top(t_stack *stack, t_stack_node *node); // If used by operations
void            push_value_to_top(t_stack *stack, int value); // If used
void			free_stack(t_stack *stack);
void			add_node_to_bottom(t_stack *stack, t_stack_node *node);
void			add_value_to_bottom(t_stack *stack, int value);

// --- Sorting Algorithms ---
int		sort_small_stack(t_stack *stack_a, t_stack *stack_b); // MODIFIED

void	sort_radix(t_stack *stack_a, t_stack *stack_b); // <--- ADD THIS LINE

// Other utilities
void	exit_error(void);
int		is_number_str(const char *str);
long	ft_atol(const char *str);
int is_sorted(t_stack *stack);
char	**ft_split(const char *s, char delimiter);
char	**split_args(int *argc, char **argv);

//Main_utils
int has_duplicates(int *arr, int size);
void print_stack(t_stack *stack, const char *name);
void	parse_arguments(int argc, char **argv, t_stack *stack_a);
void	sort_logic(t_stack *stack_a, t_stack *stack_b);
void	parse_arguments_split(char **split, t_stack *stack);
void	free_split(char **split);

//Op_push
t_stack_node *pop_from_stack(t_stack *stack);
void push_to_top(t_stack *stack, t_stack_node *node_to_push);
void pa(t_stack *stack_a, t_stack *stack_b);
void pb(t_stack *stack_a, t_stack *stack_b);

//Op_rev_rot
void rra(t_stack *stack_a, int print_op);
void rrb(t_stack *stack_b, int print_op);
void rrr(t_stack *stack_a, t_stack *stack_b);

//Op_rot
void ra(t_stack *stack_a, int print_op);
void rb(t_stack *stack_b, int print_op);
void rr(t_stack *stack_a, t_stack *stack_b);

//Op_swap
void sa(t_stack *stack_a, int print_op);
void sb(t_stack *stack_b, int print_op);
void ss(t_stack *stack_a, t_stack *stack_b);

//Ranking
void assign_ranks(t_stack *stack);

//Ranking_utils
void bubble_sort_array(int *arr, int size);

//Sort_small
void sort_two(t_stack *stack_a);
void sort_three(t_stack *stack_a);
void sort_four(t_stack *stack_a, t_stack *stack_b);
void sort_five(t_stack *stack_a, t_stack *stack_b);

#endif