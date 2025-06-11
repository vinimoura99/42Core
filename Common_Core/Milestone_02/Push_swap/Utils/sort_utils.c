/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:29:34 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/11 12:25:24 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 

find_pos 🔎📍:
Procura na pilha a posição do nó com o rank igual ao target_rank.
Retorna a posição (índice) ou -1 se não encontrar.

rotate_to_top 🔄⬆️ :
Roda a pilha para colocar o elemento da posição pos no topo, usando o
menor número de movimentos:

    📍se pos está na metade superior, faz rotações normais (ra)

    📍se está na metade inferior, faz rotações reversas (rra)

bring_to_top_a 🎯⬆️:
Traz para o topo da pilha a o elemento com rank igual a target_rank, 
usando as funções acima.

*/

#include "../Includes/push_swap.h"

int	find_pos(t_stack *stack, int target_rank)
{
	t_stack_node	*current;
	int				pos;

	current = stack->top;
	pos = 0;
	while (current)
	{
		if (current->rank == target_rank)
			return (pos);
		pos++;
		current = current->next;
	}
	return (-1);
}

void	rotate_to_top(t_stack *a, int pos, int size)
{
	int	moves;

	if (pos <= size / 2)
	{
		moves = pos;
		while (moves-- > 0)
			ra(a, 1);
	}
	else
	{
		moves = size - pos;
		while (moves-- > 0)
			rra(a, 1);
	}
}

void	bring_to_top_a(t_stack *a, int target_rank)
{
	int	pos;

	if (!a || !a->top || a->size <= 1)
		return ;
	pos = find_pos(a, target_rank);
	if (pos <= 0)
		return ;
	rotate_to_top(a, pos, a->size);
}
