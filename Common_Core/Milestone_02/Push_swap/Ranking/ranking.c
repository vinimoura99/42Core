/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:58:41 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/06 11:58:51 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

static void assign_ranks_to_nodes(t_stack *stack, int *sorted_values)
{
    t_stack_node *current_node;
    int i;

    current_node = stack->top;
    while (current_node)
    {
        i = 0;
        while (i < stack->size)
        {
            if (current_node->value == sorted_values[i])
            {
                current_node->rank = i;
                break;
            }
            i++;
        }
        current_node = current_node->next;
    }
}

void assign_ranks(t_stack *stack)
{
    int *values_array;
    int i;
    t_stack_node *current_node;

    if (!stack || !stack->top || stack->size == 0)
        return;

    values_array = malloc(sizeof(int) * stack->size);
    if (!values_array)
        exit_error();

    current_node = stack->top;
    i = 0;
    while (current_node)
    {
        values_array[i++] = current_node->value;
        current_node = current_node->next;
    }

    bubble_sort_array(values_array, stack->size);

    assign_ranks_to_nodes(stack, values_array);

    free(values_array);
}

