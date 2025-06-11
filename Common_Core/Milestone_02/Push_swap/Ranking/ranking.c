/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:07:07 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/11 12:03:14 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
✅ assign_ranks :

	Função principal que atribui um rank a cada nó da pilha stack.
	Cria um array auxiliar arr para guardar os valores da pilha.

	Chama:

		🔗 fill_array: preenche o array com os valores da pilha.

		🔗 bubble_sort_array: ordena o array.

		🔗 assign_node_ranks: para cada nó, busca seu valor no array 
        ordenado e
		atribui o índice como rank.

	Libera o array no final.

✅ Funções auxiliares:

	🔗 fill_array(int *arr, t_stack *stack): copia valores da pilha 
    para o array.

	🔗 bubble_sort_array(int *arr, int size): ordena o array usando 
    bubble sort
	otimizado (early stop se já ordenado).

	🔗 assign_node_ranks(t_stack *stack, int *arr): para cada nó da 
    pilha, encontra		seu valor no array ordenado e define o rank
    com o índice.
*/
#include "../Includes/push_swap.h"

static void	bubble_sort_array(int *arr, int size)
{
	int	swapped;
	int	i;
	int	j;
	int	temp;

	if (!arr || size < 2)
		return ;
	i = -1;
	while (++i < size - 1)
	{
		swapped = 0;
		j = -1;
		while (++j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1;
			}
		}
		if (!swapped)
			break ;
	}
}

static void	fill_array(int *arr, t_stack *stack)
{
	t_stack_node	*n;
	int				i;

	n = stack->top;
	i = 0;
	while (n)
	{
		arr[i++] = n->value;
		n = n->next;
	}
}

static void	assign_node_ranks(t_stack *stack, int *arr)
{
	t_stack_node	*n;
	int				i;

	n = stack->top;
	while (n)
	{
		i = 0;
		while (arr[i] != n->value)
			i++;
		n->rank = i;
		n = n->next;
	}
}

void	assign_ranks(t_stack *stack)
{
	int	*arr;

	if (!stack || !stack->top || stack->size == 0)
		return ;
	arr = malloc(sizeof(int) * stack->size);
	if (!arr)
		exit_error();
	fill_array(arr, stack);
	bubble_sort_array(arr, stack->size);
	assign_node_ranks(stack, arr);
	free(arr);
}
