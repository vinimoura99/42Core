#include "../push_swap.h"
#include <stdlib.h>

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
