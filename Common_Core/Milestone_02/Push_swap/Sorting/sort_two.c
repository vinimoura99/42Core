#include "../push_swap.h"

void sort_two(t_stack *stack_a)
{
    if (!stack_a || stack_a->size != 2)
        return;
    if (stack_a->top->rank > stack_a->top->next->rank)
        sa(stack_a, 1);
}
