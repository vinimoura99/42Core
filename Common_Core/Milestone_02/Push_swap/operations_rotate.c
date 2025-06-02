#include "push_swap.h"
#include <unistd.h> // For write

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
void ra(t_stack *stack_a, int print_op)
{
    t_stack_node *first;

    if (!stack_a || !stack_a->top || !stack_a->top->next)
        return; // Not enough elements to rotate

    first = stack_a->top;

    // Detach first from top
    stack_a->top = first->next;
    stack_a->top->prev = NULL;

    // Attach first to bottom
    stack_a->bottom->next = first;
    first->prev = stack_a->bottom;
    first->next = NULL;
    stack_a->bottom = first;

    if (print_op)
        write(1, "ra\n", 3);
}

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void rb(t_stack *stack_b, int print_op)
{
    t_stack_node *first;

    if (!stack_b || !stack_b->top || !stack_b->top->next)
        return;

    first = stack_b->top;

    stack_b->top = first->next;
    stack_b->top->prev = NULL;

    stack_b->bottom->next = first;
    first->prev = stack_b->bottom;
    first->next = NULL;
    stack_b->bottom = first;

    if (print_op)
        write(1, "rb\n", 3);
}

// rr : ra and rb at the same time.
void rr(t_stack *stack_a, t_stack *stack_b)
{
    ra(stack_a, 0);
    rb(stack_b, 0);
    write(1, "rr\n", 3);
}