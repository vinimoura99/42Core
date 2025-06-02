#include "push_swap.h"

// Initializes an empty stack
void stack_init(t_stack *stack)
{
    if (!stack)
        return;
    stack->top = NULL;
    stack->bottom = NULL;
    stack->size = 0;
}

// Creates a new stack node
t_stack_node *new_node(int value)
{
    t_stack_node *node;

    node = (t_stack_node *)malloc(sizeof(t_stack_node));
    if (!node)
        exit_error(); // Or handle error more gracefully if preferred
    node->value = value;
    node->rank = -1; // Initialize rank to an invalid value, to be set later
    node->prev = NULL;
    node->next = NULL;
    return (node);
}

// Pushes a new value to the top of the stack
// For push_swap, we typically add numbers to stack A in the order they are given,
// which means adding to the bottom if you consider the first argument as the "top"
// when it's first processed. Or, add to top and then effectively reverse.
// Let's implement a standard "push to top" for now.
void push_node_to_top(t_stack *stack, t_stack_node *node)
{
    if (!stack || !node)
        return;

    if (stack->top == NULL) // Stack is empty
    {
        stack->top = node;
        stack->bottom = node;
        node->next = NULL;
        node->prev = NULL;
    }
    else
    {
        node->next = stack->top;
        node->prev = NULL;
        stack->top->prev = node;
        stack->top = node;
    }
    stack->size++;
}

// Helper to create a node and push it
void push_value_to_top(t_stack *stack, int value)
{
    t_stack_node *node;

    node = new_node(value);
    push_node_to_top(stack, node);
}


// Frees all nodes in the stack
void free_stack(t_stack *stack)
{
    t_stack_node *current;
    t_stack_node *next_node;

    if (!stack || !stack->top)
        return;
    current = stack->top;
    while (current)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    stack->top = NULL;
    stack->bottom = NULL;
    stack->size = 0;
}

// (Optional for now) Function to add to the bottom of the stack
// This can be useful for initializing stack A in the order of input arguments
void add_node_to_bottom(t_stack *stack, t_stack_node *node)
{
    if (!stack || !node)
        return;
    if (stack->bottom == NULL) // stack is empty
    {
        stack->top = node;
        stack->bottom = node;
        node->next = NULL;
        node->prev = NULL;
    }
    else
    {
        stack->bottom->next = node;
        node->prev = stack->bottom;
        node->next = NULL;
        stack->bottom = node;
    }
    stack->size++;
}

// Helper to create a node and add its value to the bottom
void add_value_to_bottom(t_stack *stack, int value)
{
    t_stack_node *node;
    node = new_node(value);
    add_node_to_bottom(stack, node);
}