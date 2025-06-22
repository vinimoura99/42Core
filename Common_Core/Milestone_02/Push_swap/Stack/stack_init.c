#include "../push_swap.h"
#include <stdlib.h>

void stack_init(t_stack *stack)
{
    if (!stack)
        return;
    stack->top = NULL;
    stack->bottom = NULL;
    stack->size = 0;
}


