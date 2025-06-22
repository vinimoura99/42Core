/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:42:51 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/06 11:44:07 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

void ra(t_stack *stack_a, int print_op)
{
    t_stack_node *first;

    if (!stack_a || !stack_a->top || !stack_a->top->next)
        return;

    first = stack_a->top;

    stack_a->top = first->next;
    stack_a->top->prev = NULL;

    stack_a->bottom->next = first;
    first->prev = stack_a->bottom;
    first->next = NULL;
    stack_a->bottom = first;

    if (print_op)
        write(1, "ra\n", 3);
}

void rb(t_stack *stack_b, int print_op)
{
    t_stack_node *first;

    if (!stack_b || !stack_b->top || !stack_b->top->next)
        return;

    first = stack_b->top;

    stack_b->top = first->next;
    stack_b->top->prev = NULL;

    stack_b->bottom->next = first;
    first->prev = stack_b->bottom;
    first->next = NULL;
    stack_b->bottom = first;

    if (print_op)
        write(1, "rb\n", 3);
}

void rr(t_stack *stack_a, t_stack *stack_b)
{
    ra(stack_a, 0);
    rb(stack_b, 0);
    write(1, "rr\n", 3);
}