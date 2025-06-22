/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:27:37 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/06 12:46:58 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h> 
#include <stdlib.h>

char	**split_args(int *argc, char **argv)
{
	if (*argc == 2)
	{
		char **split = ft_split(argv[1], ' ');
		int count = 0;
		while (split[count])
			count++;
		*argc = count + 1; // +1 para manter compatível com seu loop
		return (split);
	}
	return (argv);
}

void	parse_arguments(int argc, char **argv, t_stack *stack_a)
{
    long			temp_val;
    t_stack_node	*current;
    int				i;

    i = 1;
    while (i < argc)
    {
        if (!is_number_str(argv[i]))
        {
            free_stack(stack_a);
            exit_error();
        }
        temp_val = ft_atol(argv[i]);
        current = stack_a->top;
        while (current)
        {
            if (current->value == (int)temp_val)
            {
                free_stack(stack_a);
                exit_error();
            }
            current = current->next;
        }
        add_value_to_bottom(stack_a, (int)temp_val);
        i++;
    }
}

void	sort_logic(t_stack *stack_a, t_stack *stack_b)
{
    if (!is_sorted(stack_a))
    {
        if (stack_a->size <= 5)
            sort_small_stack(stack_a, stack_b);
        else
            sort_radix(stack_a, stack_b);
    }
}
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