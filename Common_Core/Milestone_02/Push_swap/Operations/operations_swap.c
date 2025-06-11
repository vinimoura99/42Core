/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:10:30 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/11 12:07:50 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*    

✅ sa e sb: trocam os dois primeiros elementos do topo das pilhas A e B,
 respectivamente.

✅ ss: executa sa e sb simultaneamente, mas imprime apenas "ss\n".

🧠 Como funcionam sa e sb?

    🔗 Verificam se a pilha tem ao menos dois nós.

    🔗 Ajustam os ponteiros next e prev para inverter a ordem dos dois 
    primeiros nós.

    🔗 Atualizam top para o novo primeiro nó.

    🔗 Atualizam bottom se a lista tem exatamente dois nós.

    🔗 Imprimem o nome da operação se print_op for verdadeiro.

✅ ss :
    
    🔗 Chama sa e sb sem imprimir cada uma.
    
    🔗 Imprime "ss\n" para indicar o swap duplo.*/

#include "../Includes/push_swap.h"
#include <unistd.h>

void	sa(t_stack *stack_a, int print_op)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return ;
	first = stack_a->top;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	if (second->next)
		second->next->prev = first;
	else
		stack_a->bottom = first;
	second->prev = NULL;
	second->next = first;
	stack_a->top = second;
	if (print_op)
		write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b, int print_op)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!stack_b || !stack_b->top || !stack_b->top->next)
		return ;
	first = stack_b->top;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	if (second->next)
		second->next->prev = first;
	else
		stack_b->bottom = first;
	second->prev = NULL;
	second->next = first;
	stack_b->top = second;
	if (print_op)
		write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	write(1, "ss\n", 3);
}
