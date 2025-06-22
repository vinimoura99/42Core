/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:25:58 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/06 13:00:38 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h> 
#include <stdlib.h>

int	*stack_to_array(t_stack *stack)
{
	int				*arr;
	t_stack_node	*current = stack->top;
	int				i = 0;

	arr = malloc(sizeof(int) * stack->size);
	if (!arr)
		exit_error(); // ou return NULL
	while (current)
	{
		arr[i++] = current->value;
		current = current->next;
	}
	return (arr);
}


int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	**split = NULL;

	stack_init(&stack_a);
	stack_init(&stack_b);

	if (argc < 2)
		return (0);

	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split || !split[0])
			return (write(2, "Error\n", 6), 1);
		parse_arguments_split(split, &stack_a); // usa split[] em vez de argv
	}
	else
		parse_arguments(argc, argv, &stack_a); // normal com múltiplos args

	// validações + lógica
	int *arr = stack_to_array(&stack_a);
    if (has_duplicates(arr, stack_a.size))
    {
        free(arr);
        write(2, "Error\n", 6);
        exit(EXIT_FAILURE);
    }
    free(arr);

	// lógica de sort...
	sort_logic(&stack_a, &stack_b);

	// liberar memória
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (split)
		free_split(split);
	return (0);
}


