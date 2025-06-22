#include "../push_swap.h"

void execute_sort_three(t_stack *stack_a, int r0, int r1, int r2)
{
    if (r0 < r1 && r1 < r2)
        return;
    if (r0 < r2 && r2 < r1)
    {
        rra(stack_a, 1);
        sa(stack_a, 1);
        return;
    }
    if (r1 < r0 && r0 < r2)
    {
        sa(stack_a, 1);
        return;
    }
    if (r2 < r1 && r1 > r0 && r0 < r1)
    {
        rra(stack_a, 1);
        return;
    }
    if (r1 < r2 && r2 < r0)
    {
        ra(stack_a, 1);
        return;
    }
    sa(stack_a, 1);
    rra(stack_a, 1);
}

void sort_three(t_stack *stack_a)
{
    int r0;
    int r1;
    int r2;

    if (!stack_a || stack_a->size != 3)
        return;

    r0 = stack_a->top->rank;
    r1 = stack_a->top->next->rank;
    r2 = stack_a->top->next->next->rank;

    execute_sort_three(stack_a, r0, r1, r2);
}
