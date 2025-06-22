#include "../push_swap.h"

static void bring_to_top_a(t_stack *stack_a, int target_rank)
{
    t_stack_node *cur = stack_a->top;
    int pos = 0;
    int size;

    if (!stack_a || !cur || stack_a->size <= 1)
        return;
    size = stack_a->size;
    while (cur && cur->rank != target_rank)
    {
        cur = cur->next;
        pos++;
    }
    if (!cur || pos == 0)
        return;
    if (pos <= size / 2)
        while (pos-- > 0)
            ra(stack_a, 1);
    else
        while (size - pos-- > 0)
            rra(stack_a, 1);
}

void sort_four(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a || stack_a->size != 4)
        return;
    bring_to_top_a(stack_a, 0);
    pb(stack_a, stack_b);
    sort_three(stack_a);
    pa(stack_a, stack_b);
}