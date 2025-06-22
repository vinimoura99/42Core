/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:34:00 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/06 12:44:18 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

void rra(t_stack *stack_a, int print_op)
{
    t_stack_node *last;

    if (!stack_a || !stack_a->top || !stack_a->top->next)
        return;

    last = stack_a->bottom;

   
    stack_a->bottom = last->prev;
    stack_a->bottom->next = NULL;

    
    last->next = stack_a->top;
    last->prev = NULL;
    stack_a->top->prev = last;
    stack_a->top = last;

    if (print_op)
        write(1, "rra\n", 4);
}

void rrb(t_stack *stack_b, int print_op)
{
    t_stack_node *last;

    if (!stack_b || !stack_b->top || !stack_b->top->next)
        return;

    last = stack_b->bottom;

    stack_b->bottom = last->prev;
    stack_b->bottom->next = NULL;

    last->next = stack_b->top;
    last->prev = NULL;
    stack_b->top->prev = last;
    stack_b->top = last;

    if (print_op)
        write(1, "rrb\n", 4);
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
    rra(stack_a, 0);
    rrb(stack_b, 0);
    write(1, "rrr\n", 4);
}
