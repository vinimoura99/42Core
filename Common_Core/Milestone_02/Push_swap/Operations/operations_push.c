/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:31:25 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/06 12:42:06 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack_node *pop_from_stack(t_stack *stack)
{
    t_stack_node *node_to_pop;

    if (!stack || !stack->top)
        return (NULL);

    node_to_pop = stack->top;
    stack->top = stack->top->next;
    if (stack->top)
        stack->top->prev = NULL;
    else
        stack->bottom = NULL;

    stack->size--;
    node_to_pop->next = NULL;
    node_to_pop->prev = NULL;
    return (node_to_pop);
}

void push_to_top(t_stack *stack, t_stack_node *node_to_push)
{
    if (!stack || !node_to_push)
        return;

    if (stack->top == NULL) // Stack is empty
    {
        stack->top = node_to_push;
        stack->bottom = node_to_push;
        node_to_push->next = NULL;
        node_to_push->prev = NULL;
    }
    else
    {
        node_to_push->next = stack->top;
        node_to_push->prev = NULL;
        stack->top->prev = node_to_push;
        stack->top = node_to_push;
    }
    stack->size++;
}
void pa(t_stack *stack_a, t_stack *stack_b)
{
    t_stack_node *node_to_move;

    if (!stack_b || !stack_b->top)
        return; // Stack B is empty

    node_to_move = pop_from_stack(stack_b);
    if (node_to_move)
    {
        push_to_top(stack_a, node_to_move);
        write(1, "pa\n", 3);
    }
}
void pb(t_stack *stack_a, t_stack *stack_b)
{
    t_stack_node *node_to_move;

    if (!stack_a || !stack_a->top)
        return;
    node_to_move = pop_from_stack(stack_a);
    if (node_to_move)
    {
        push_to_top(stack_b, node_to_move);
        write(1, "pb\n", 3);
    }
}
