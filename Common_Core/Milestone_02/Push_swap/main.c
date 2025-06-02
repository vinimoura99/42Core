#include "push_swap.h"
#include <stdio.h> 
#include <stdlib.h>

void print_stack(t_stack *stack, const char *name)
{
    t_stack_node *current;

    if (!stack)
        return;
    printf("Stack %s (size %d):\n", name, stack->size);
    current = stack->top;
    if (!current)
    {
        printf("(empty)\n");
        return;
    }
    while (current)
    {
        printf("Value: %d (Rank: %d)\n", current->value, current->rank);
        current = current->next;
    }
    printf("------\n");
}

int has_duplicates(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
                return (1); 
        }
    }
    return (0);
}
int main(int argc, char **argv)
{
    t_stack	stack_a;
    t_stack	stack_b;

    if (argc < 2)
        return (1);

    stack_init(&stack_a);
    stack_init(&stack_b);

    for (int i = 1; i < argc; i++)
    {
        long temp_val;
        if (!is_number_str(argv[i]))
        {
            free_stack(&stack_a);
            exit_error();
        }
        temp_val = ft_atol(argv[i]);
        t_stack_node *current = stack_a.top;
        while(current)
        {
            if (current->value == (int)temp_val)
            {
                free_stack(&stack_a);
                exit_error();
            }
            current = current->next;
        }
        add_value_to_bottom(&stack_a, (int)temp_val);
    }

    assign_ranks(&stack_a);
   
    if (!is_sorted(&stack_a)) 
    {
        if (stack_a.size <= 5)
        {
            sort_small_stack(&stack_a, &stack_b);
        }
        else // stack_a.size > 5
        {
            sort_radix(&stack_a, &stack_b); 
        }
    }

    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}