/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:39:08 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/11 12:08:01 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
✅ get_args

    Trata entrada do programa.

    Se houver apenas um argumento (argc == 2), ele o divide com ft_split.

    Caso contrário, usa os argumentos diretamente.

    Define should_free para saber se precisa liberar a memória de ft_split.

✅ sort_stack

    Decide qual algoritmo de ordenação usar:

        Se a pilha tiver até 5 elementos, usa sort_small_stack.

        Caso contrário, usa sort_radix.

✅ main

    Valida número de argumentos.

    Prepara os argumentos para parsing.

    Inicializa as pilhas a e b.

    Converte argumentos em inteiros e os armazena na pilha a.

    Atribui "ranks" aos elementos da pilha.

    Ordena a pilha com o algoritmo adequado.

    Libera os recursos utilizados. */

#include "../Includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

static char	**get_args(int argc, char **argv, int *should_free)
{
	char	**args;

	*should_free = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		*should_free = 1;
	}
	else
		args = &argv[1];
	return (args);
}

static void	sort_stack(t_stack *a, t_stack *b)
{
	if (!is_sorted(a))
	{
		if (a->size <= 5)
			sort_small_stack(a, b);
		else
			sort_radix(a, b);
	}
}

int	main(int argc, char **argv)
{
	char	**args;
	int		should_free;
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (1);
	args = get_args(argc, argv, &should_free);
	if (!args)
		exit_error();
	stack_init(&stack_a);
	stack_init(&stack_b);
	parse_args(args, &stack_a, should_free);
	assign_ranks(&stack_a);
	sort_stack(&stack_a, &stack_b);
	free_resources(&stack_a, &stack_b, args, should_free);
	return (0);
}
