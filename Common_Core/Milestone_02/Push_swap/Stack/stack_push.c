#include "../push_swap.h"

void push_node_to_top(t_stack *stack, t_stack_node *node)
{
    if (!stack || !node)
        return;

    if (stack->top == NULL)
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

void push_value_to_top(t_stack *stack, int value)
{
    t_stack_node *node;

    node = new_node(value);
    push_node_to_top(stack, node);
}

void add_node_to_bottom(t_stack *stack, t_stack_node *node)
{
    if (!stack || !node)
        return;
    if (stack->bottom == NULL)
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

void add_value_to_bottom(t_stack *stack, int value)
{
    t_stack_node *node;
    node = new_node(value);
    add_node_to_bottom(stack, node);
}
