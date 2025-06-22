#include "../push_swap.h"

int sort_small_stack(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a || stack_a->size <= 1)
        return 1;
    if (is_sorted(stack_a))
        return 1;
    if (stack_a->size == 2)
    {
        sort_two(stack_a);
        return 1;
    }
    else if (stack_a->size == 3)
    {
        sort_three(stack_a);
        return 1;
    }
    else if (stack_a->size == 4)
    {
        sort_four(stack_a, stack_b);
        return 1;
    }
    else if (stack_a->size == 5)
    {
        sort_five(stack_a, stack_b);
        return 1;
    }
    return 0;
}
