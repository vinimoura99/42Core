/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:03:09 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/11 12:04:19 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
✅ pop_from_stack :

    Remove o elemento do topo da pilha.

    Atualiza ponteiros top, bottom e size.

    Retorna o nó removido.

✅ push_to_top : 

    Insere um nó no topo da pilha.

    Atualiza top, bottom e size.

    Garante integridade dos ponteiros (dúplamente encadeado).

-------------------------------------------------------------

✅ pa(stack_a, stack_b) :

    Move o topo da pilha B para A.

    Escreve pa\n na saída se houver movimento.

✅ pb(stack_a, stack_b) :

    Move o topo da pilha A para B.

    Escreve pb\n na saída se houver movimento.*/

#include "../Includes/push_swap.h"
#include <unistd.h>

static t_stack_node	*pop_from_stack(t_stack *stack)
{
	t_stack_node	*node_to_pop;

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

static void	push_to_top(t_stack *stack, t_stack_node *node_to_push)
{
	if (!stack || !node_to_push)
		return ;
	if (stack->top == NULL)
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

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*node_to_move;

	if (!stack_b || !stack_b->top)
		return ;
	node_to_move = pop_from_stack(stack_b);
	if (node_to_move)
	{
		push_to_top(stack_a, node_to_move);
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*node_to_move;

	if (!stack_a || !stack_a->top)
		return ;
	node_to_move = pop_from_stack(stack_a);
	if (node_to_move)
	{
		push_to_top(stack_b, node_to_move);
		write(1, "pb\n", 3);
	}
}
