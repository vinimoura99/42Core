/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:03:59 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/06 12:04:00 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int get_max_bits(t_stack *stack_a)
{
    int max_rank;
    int max_bits;

    if (!stack_a || stack_a->size == 0)
        return 0;
    max_rank = stack_a->size - 1;
    max_bits = 0;
    if (max_rank == 0)
        return 1;
    while ((max_rank >> max_bits) != 0)
        max_bits++;
    if (max_bits == 0 && max_rank == 0 && stack_a->size > 0)
        return 1;
    return max_bits;
}

static void process_bit(t_stack *stack_a, t_stack *stack_b, int bit)
{
    int i;
    int size = stack_a->size;
    int rank_value;

    i = 0;
    while (i < size)
    {
        rank_value = stack_a->top->rank;
        if (((rank_value >> bit) & 1) == 0)
            pb(stack_a, stack_b);
        else
            ra(stack_a, 1);
        i++;
    }
}

static void push_back_all(t_stack *stack_a, t_stack *stack_b)
{
    while (stack_b->size > 0)
        pa(stack_a, stack_b);
}

void sort_radix(t_stack *stack_a, t_stack *stack_b)
{
    int max_bits;
    int bit;

    if (!stack_a || is_sorted(stack_a))
        return;

    max_bits = get_max_bits(stack_a);
    bit = 0;
    while (bit < max_bits)
    {
        process_bit(stack_a, stack_b, bit);
        push_back_all(stack_a, stack_b);
        bit++;
    }
}
