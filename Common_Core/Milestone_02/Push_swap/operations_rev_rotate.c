#include "push_swap.h"
#include <unistd.h> // For write

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
void rra(t_stack *stack_a, int print_op)
{
    t_stack_node *last;

    if (!stack_a || !stack_a->top || !stack_a->top->next)
        return; // Not enough elements to reverse rotate

    last = stack_a->bottom;

    // Detach last from bottom
    stack_a->bottom = last->prev;
    stack_a->bottom->next = NULL;

    // Attach last to top
    last->next = stack_a->top;
    last->prev = NULL;
    stack_a->top->prev = last;
    stack_a->top = last;

    if (print_op)
        write(1, "rra\n", 4);
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void rrb(t_stack *stack_b, int print_op)
{
    t_stack_node *last;

    if (!stack_b || !stack_b->top || !stack_b->top->next)
        return;

    last = stack_b->bottom;

    stack_b->bottom = last->prev;
    stack_b->bottom->next = NULL;

    last->next = stack_b->top;
    last->prev = NULL;
    stack_b->top->prev = last;
    stack_b->top = last;

    if (print_op)
        write(1, "rrb\n", 4);
}

// rrr : rra and rrb at the same time.
void rrr(t_stack *stack_a, t_stack *stack_b)
{
    rra(stack_a, 0);
    rrb(stack_b, 0);
    write(1, "rrr\n", 4);
}