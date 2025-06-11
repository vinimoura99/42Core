/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:41:33 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/11 12:23:55 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
print_stack 🖨️📋 :
Mostra a pilha no console: nome, tamanho, valores e ranks. Indica se está vazia.

free_split 🗑️🧹: 
Libera a memória de um array de strings (char **).

parse_args 🔍➡️📥 :
Converte strings em números, verifica validade e duplicatas, adiciona na pilha. 
Em erro, libera tudo e encerra.

has_duplicate 🔎⚠️:
Confere se um valor já está na pilha. Retorna 1 se tiver duplicado.

free_resources ♻️🧹:
Libera pilhas e, opcionalmente, o array de strings. */

#include "../Includes/push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	print_stack(t_stack *stack, const char *name)
{
	t_stack_node	*current;

	if (!stack)
		return ;
	ft_putstr("Stack ");
	ft_putstr(name);
	ft_putstr(" (size ");
	ft_putnbr(stack->size);
	ft_putendl("):");
	current = stack->top;
	if (!current)
	{
		ft_putendl("(empty)");
		return ;
	}
	while (current)
	{
		ft_putstr("Value: ");
		ft_putnbr(current->value);
		ft_putstr(" (Rank: ");
		ft_putnbr(current->rank);
		ft_putendl(")");
		current = current->next;
	}
	ft_putendl("------");
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	parse_args(char **args, t_stack *stack_a, int should_free)
{
	int		i;
	long	temp_val;

	i = 0;
	while (args[i])
	{
		temp_val = ft_atol(args[i]);
		if (!is_number_str(args[i]) || has_duplicate(stack_a, (int)temp_val))
		{
			free_stack(stack_a);
			if (should_free)
				free_split(args);
			exit_error();
		}
		add_value_to_bottom(stack_a, (int)temp_val);
		i++;
	}
}

int	has_duplicate(t_stack *stack_a, int value)
{
	t_stack_node	*current;

	current = stack_a->top;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

void	free_resources(t_stack *stack_a, t_stack *stack_b, char **args,
		int should_free)
{
	free_stack(stack_a);
	free_stack(stack_b);
	if (should_free)
		free_split(args);
}
