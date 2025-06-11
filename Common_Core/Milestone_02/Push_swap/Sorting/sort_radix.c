/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:00:40 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/11 12:03:41 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
✅ get_max_bits : 

    Calcula quantos bits são necessários para representar o maior rank na 
    pilha stack_a.

    Usa o tamanho da pilha (stack_a->size) para determinar o maior 
    rank (size - 1).

    Conta quantos bits são necessários para representar esse maior rank 
    (quantidade de bits até que o deslocamento do maior rank seja zero).

    Retorna o número de bits para usar no radix sort.

✅ sort_radix :

    Ordena a pilha a usando o algoritmo Radix Sort por bits nos ranks.

    Para cada bit do menor para o maior (i de 0 até bits-1):

        Itera por todos os elementos da pilha a.

        Se o bit i do rank do topo for 0, envia o elemento para a pilha b 
        (pb).

        Se o bit for 1, rotaciona a pilha a (ra).

    Após processar todos os elementos para o bit atual, traz todos os
    elementos de volta da pilha b para a pilha a (pa).

    Repete o processo para todos os bits, garantindo a ordenação.

❌ Observações :

    A função já ignora ordenação se a pilha a já estiver ordenada.

    Usa operações padrão do push_swap (pb, pa, ra) e o campo rank 
    que deve ter sido atribuído antes (com assign_ranks).

    É um método eficiente para ordenar grandes pilhas usando apenas 
    operações permitidas. */

#include "../Includes/push_swap.h"

static int	get_max_bits(t_stack *stack_a)
{
	int	max_rank;
	int	max_bits;

	if (!stack_a || stack_a->size == 0)
		return (0);
	max_rank = stack_a->size - 1;
	max_bits = 0;
	if (max_rank == 0)
		return (1);
	while ((max_rank >> max_bits) != 0)
	{
		max_bits++;
	}
	if (max_bits == 0 && max_rank == 0 && stack_a->size > 0)
		return (1);
	return (max_bits);
}

void	sort_radix(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	size;
	int	bits;
	int	rank;

	if (!a || is_sorted(a))
		return ;
	bits = get_max_bits(a);
	i = -1;
	while (++i < bits)
	{
		size = a->size;
		j = -1;
		while (++j < size)
		{
			rank = a->top->rank;
			if (((rank >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a, 1);
		}
		while (b->size)
			pa(a, b);
	}
}
