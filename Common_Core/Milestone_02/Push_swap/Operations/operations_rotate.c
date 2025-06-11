/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:09:08 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/11 12:06:55 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
🧠 O que é "rotate" (ra, rb, rr)?

    Move o primeiro elemento da pilha para o final.

    Todos os outros elementos sobem uma posição.

✅ ra(t_stack *stack_a, int print_op) :

    Move o topo da pilha A para o fundo.

    Se print_op == 1, escreve "ra\n".

✅ rb(t_stack *stack_b, int print_op) :

    Idêntico ao ra, mas para a pilha B.

    Se print_op == 1, escreve "rb\n".

✅ rr(t_stack *stack_a, t_stack *stack_b) :

    Executa ra e rb sem print individual.

    Escreve "rr\n" no final. 
    
💡 Lógica interna:

    🔗 Guarda o primeiro nó (top).

    🔗 Atualiza top para o próximo.

    🔗 Remove o antigo topo da frente.

    🔗 Insere esse antigo topo no final:

        💡 Aponta bottom->next para ele.

        💡 Atualiza ponteiros e bottom. */

#include "../Includes/push_swap.h"
#include <unistd.h>

void	ra(t_stack *stack_a, int print_op)
{
	t_stack_node	*first;

	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return ;
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

void	rb(t_stack *stack_b, int print_op)
{
	t_stack_node	*first;

	if (!stack_b || !stack_b->top || !stack_b->top->next)
		return ;
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

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	write(1, "rr\n", 3);
}
