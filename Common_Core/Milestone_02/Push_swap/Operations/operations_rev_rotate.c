/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:05:27 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/11 12:13:58 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
✅ rra(t_stack *stack_a, int print_op) :

    Move o último elemento da pilha A para o topo.

    Só executa se houver pelo menos 2 elementos.

    Escreve rra\n se print_op for verdadeiro.

✅ rrb(t_stack *stack_b, int print_op) :

    Mesma lógica que rra, mas aplicada à pilha B.

✅ rrr(t_stack *stack_a, t_stack *stack_b) :

    Executa rra e rrb sem imprimir.

    Depois escreve rrr\n, indicando operação dupla.
    
✅ Lógica de reverse rotate:

    🔗 Pega o último nó (bottom).

    🔗 Atualiza o bottom para ser o anterior.

    🔗 Remove o antigo último da cauda.

    🔗 Move esse nó para o topo da pilha:

        💡 Aponta last->next para o antigo topo.

        💡 Atualiza ponteiros prev e top.*/

#include "../Includes/push_swap.h"
#include <unistd.h>

void	rra(t_stack *stack_a, int print_op)
{
	t_stack_node	*last;

	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return ;
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

void	rrb(t_stack *stack_b, int print_op)
{
	t_stack_node	*last;

	if (!stack_b || !stack_b->top || !stack_b->top->next)
		return ;
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

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	write(1, "rrr\n", 4);
}
