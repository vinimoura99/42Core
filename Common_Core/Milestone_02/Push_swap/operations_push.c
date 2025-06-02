#include "push_swap.h"
#include <unistd.h> // For write

// Helper function to remove the top node from a stack and return it
static t_stack_node *pop_from_stack(t_stack *stack)
{
    t_stack_node *node_to_pop;

    if (!stack || !stack->top)
        return (NULL);

    node_to_pop = stack->top;
    stack->top = stack->top->next;
    if (stack->top)
        stack->top->prev = NULL;
    else // Stack became empty
        stack->bottom = NULL;

    stack->size--;
    node_to_pop->next = NULL; // Detach the node completely
    node_to_pop->prev = NULL;
    return (node_to_pop);
}

// Helper function to add a node to the top of a stack
// (This is similar to push_node_to_top from stack_utils, but self-contained here for clarity
// or you can reuse the one from stack_utils if you make it non-static and declare in .h)
static void push_to_top(t_stack *stack, t_stack_node *node_to_push)
{
    if (!stack || !node_to_push)
        return;

    if (stack->top == NULL) // Stack is empty
    {
        stack->top = node_to_push;
        stack->bottom = node_to_push;
        node_to_push->next = NULL;
        node_to_push->prev = NULL;
    }
    else
    {
        node_to_push->next = stack->top;
        node_to_push->prev = NULL;
        stack->top->prev = node_to_push;
        stack->top = node_to_push;
    }
    stack->size++;
}


// pa (push a): Take the first element at the top of b and put it at the top of a.
// Does nothing if b is empty.
void pa(t_stack *stack_a, t_stack *stack_b)
{
    t_stack_node *node_to_move;

    if (!stack_b || !stack_b->top)
        return; // Stack B is empty

    node_to_move = pop_from_stack(stack_b);
    if (node_to_move)
    {
        push_to_top(stack_a, node_to_move);
        write(1, "pa\n", 3);
    }
}

// pb (push b): Take the first element at the top of a and put it at the top of b.
// Does nothing if a is empty.
void pb(t_stack *stack_a, t_stack *stack_b)
{
    t_stack_node *node_to_move;

    if (!stack_a || !stack_a->top)
        return; // Stack A is empty

    node_to_move = pop_from_stack(stack_a);
    if (node_to_move)
    {
        push_to_top(stack_b, node_to_move);
        write(1, "pb\n", 3);
    }
}