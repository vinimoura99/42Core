/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:27:28 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/11 12:13:48 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
✅ Lógica Geral :

    Se a pilha já estiver ordenada ou tiver 1 ou nenhum elemento, não faz nada.

    Usa algoritmos otimizados para poucos elementos:

        2 elementos: faz um sa se estiverem fora de ordem.

        3 elementos: analisa os ranks e faz combinações de sa, ra, rra para 
        ordenar.

        4 ou 5 elementos: empurra os menores elementos para stack_b, ordena 
        os 3 restantes e depois traz os menores de volta com pa.

🔨 Resumo por função :

    📍 sort_two:
    Se o elemento do topo for maior que o segundo, faz sa.

    📍 sort_three:
    Detecta a posição dos ranks (valores) e aplica a menor sequência possível 
    de sa, ra, rra para ordenar 3 elementos.

    📍 sort_four:
    Move o menor elemento (rank 0) para stack_b, ordena os 3 restantes e
     depois faz pa.

    📍 sort_five:
    Move os dois menores elementos (ranks 0 e 1) para stack_b, ordena os 3 
    restantes e traz os dois de volta com pa.

    📍 sort_small_stack:
    Decide qual das funções acima usar com base no tamanho da pilha a.*/

#include "../Includes/push_swap.h"

static void	sort_two(t_stack *stack_a)
{
	if (!stack_a || stack_a->size != 2)
		return ;
	if (stack_a->top->rank > stack_a->top->next->rank)
		sa(stack_a, 1);
}

static void	sort_three(t_stack *a)
{
	int	r0;
	int	r1;
	int	r2;

	if (!a || a->size != 3)
		return ;
	r0 = a->top->rank;
	r1 = a->top->next->rank;
	r2 = a->top->next->next->rank;
	if (r0 < r1 && r1 < r2)
		return ;
	if (r0 < r2 && r2 < r1)
	{
		rra(a, 1);
		sa(a, 1);
	}
	else if (r1 < r0 && r0 < r2)
		sa(a, 1);
	else if (r2 < r0 && r0 < r1)
		rra(a, 1);
	else if (r1 < r2)
		ra(a, 1);
	else
		sa(a, 1);
}

static void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || stack_a->size != 4)
		return ;
	bring_to_top_a(stack_a, 0);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

static void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || stack_a->size != 5)
		return ;
	bring_to_top_a(stack_a, 0);
	pb(stack_a, stack_b);
	bring_to_top_a(stack_a, 1);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

int	sort_small_stack(t_stack *a, t_stack *b)
{
	if (!a || a->size <= 1 || is_sorted(a))
		return (1);
	if (a->size == 2)
	{
		sort_two(a);
		return (1);
	}
	if (a->size == 3)
	{
		sort_three(a);
		return (1);
	}
	if (a->size == 4)
	{
		sort_four(a, b);
		return (1);
	}
	if (a->size == 5)
	{
		sort_five(a, b);
		return (1);
	}
	return (0);
}
