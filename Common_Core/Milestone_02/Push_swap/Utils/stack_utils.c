/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:06:40 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/11 12:31:13 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
stack_init 🆕🗃️ :
	Inicializa uma pilha vazia, definindo topo, base como NULL e tamanho 0.

push_node_to_top ⬆️📦 :
	Coloca um nó no topo da pilha.
	Se a pilha estiver vazia, topo e base apontam para o nó.
	Se não, conecta o novo nó antes do topo atual.

push_value_to_top ➕⬆️ :
	Cria um nó com o valor dado e chama push_node_to_top para colocar no topo.

add_node_to_bottom ➡️📦 :
	Adiciona um nó no final (base) da pilha.
		Se pilha vazia, topo e base apontam para o nó.
		Se não, conecta o novo nó após o nó base atual.

add_value_to_bottom ➕➡️ :
Cria um nó com o valor dado e chama add_node_to_bottom para colocar na base. */

#include "../Includes/push_swap.h"

void	stack_init(t_stack *stack)
{
	if (!stack)
		return ;
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

void	push_node_to_top(t_stack *stack, t_stack_node *node)
{
	if (!stack || !node)
		return ;
	if (stack->top == NULL)
	{
		stack->top = node;
		stack->bottom = node;
		node->next = NULL;
		node->prev = NULL;
	}
	else
	{
		node->next = stack->top;
		node->prev = NULL;
		stack->top->prev = node;
		stack->top = node;
	}
	stack->size++;
}

void	push_value_to_top(t_stack *stack, int value)
{
	t_stack_node	*node;

	node = new_node(value);
	push_node_to_top(stack, node);
}

void	add_node_to_bottom(t_stack *stack, t_stack_node *node)
{
	if (!stack || !node)
		return ;
	if (stack->bottom == NULL)
	{
		stack->top = node;
		stack->bottom = node;
		node->next = NULL;
		node->prev = NULL;
	}
	else
	{
		stack->bottom->next = node;
		node->prev = stack->bottom;
		node->next = NULL;
		stack->bottom = node;
	}
	stack->size++;
}

void	add_value_to_bottom(t_stack *stack, int value)
{
	t_stack_node	*node;

	node = new_node(value);
	add_node_to_bottom(stack, node);
}
