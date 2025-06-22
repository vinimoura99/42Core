#include "../push_swap.h"
#include <stdlib.h>

t_stack_node *new_node(int value)
{
    t_stack_node *node;

    node = (t_stack_node *)malloc(sizeof(t_stack_node));
    if (!node)
        exit_error();
    node->value = value;
    node->rank = -1;
    node->prev = NULL;
    node->next = NULL;
    return (node);
}