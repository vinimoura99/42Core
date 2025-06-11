/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:37:14 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/11 12:34:35 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Funções de impressão:

	ft_putstr 📝➡️📺
	Imprime uma string no terminal caractere a caractere.

	ft_putendl 📝➡️📺 + ⏎
	Imprime uma string e pula linha.

	ft_putnbr 🔢➡️📺
	Imprime um número inteiro no terminal, tratando número negativo e o limite
	do int especial (-2147483648).

Funções de gerenciamento de pilha:

	free_stack 🗑️🗃️
	Libera toda a memória dos nós da pilha, reseta ponteiros e tamanho.

	new_node 🆕📦
	Cria um novo nó com valor dado, inicializa rank com -1,
		e ponteiros prev e next
		como NULL. Sai do programa em caso de erro de alocação.

  */

#include "../Includes/push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(const char *s)
{
	if (!s)
		return ;
	while (*s)
		write(1, s++, 1);
}

void	ft_putendl(const char *s)
{
	ft_putstr(s);
	write(1, "\n", 1);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
}

void	free_stack(t_stack *stack)
{
	t_stack_node	*current;
	t_stack_node	*next_node;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

t_stack_node	*new_node(int value)
{
	t_stack_node	*node;

	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!node)
		exit_error();
	node->value = value;
	node->rank = -1;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
