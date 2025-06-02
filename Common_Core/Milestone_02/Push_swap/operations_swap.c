#include "push_swap.h"
#include <unistd.h> // For write

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Does nothing if there is only one or no elements.
void sa(t_stack *stack_a, int print_op)
{
    t_stack_node *first;
    t_stack_node *second;

    if (!stack_a || !stack_a->top || !stack_a->top->next)
        return; // Not enough elements to swap

    first = stack_a->top;
    second = first->next;

    // Adjust pointers
    first->next = second->next;
    first->prev = second; // second will become the new top
    if (second->next)
        second->next->prev = first;
    else // second was the bottom element
        stack_a->bottom = first;

    second->prev = NULL; // second is now the top
    second->next = first;
    stack_a->top = second;

    if (print_op)
        write(1, "sa\n", 3);
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Does nothing if there is only one or no elements.
void sb(t_stack *stack_b, int print_op)
{
    t_stack_node *first;
    t_stack_node *second;

    if (!stack_b || !stack_b->top || !stack_b->top->next)
        return;

    first = stack_b->top;
    second = first->next;

    first->next = second->next;
    first->prev = second;
    if (second->next)
        second->next->prev = first;
    else
        stack_b->bottom = first;

    second->prev = NULL;
    second->next = first;
    stack_b->top = second;

    if (print_op)
        write(1, "sb\n", 3);
}

// ss : sa and sb at the same time.
void ss(t_stack *stack_a, t_stack *stack_b)
{
    sa(stack_a, 0); // Perform sa without printing
    sb(stack_b, 0); // Perform sb without printing
    write(1, "ss\n", 3);
}