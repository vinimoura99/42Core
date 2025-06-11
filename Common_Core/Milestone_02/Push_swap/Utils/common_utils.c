/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:40:22 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/11 12:12:06 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
✅is_sorted :
Verifica se a pilha está ordenada (em ordem crescente pelo rank).
Retorna 1 se estiver ordenada ou vazia; 0 se encontrar algum rank fora de
ordem.

✅ word_dup :
Duplica uma substring com len caracteres a partir de um ponteiro start.
Retorna a nova string alocada.

✅ count_words :
Conta quantas palavras existem em uma string s, separadas pelo delimitador c.

✅ fill_split :
Preenche um array de strings com as palavras extraídas da string original,
usando word_dup.

✅ ft_split :
Divide a string s em várias substrings com base no delimitador c.
Retorna um array de strings (char **) terminando com NULL. */

#include "../Includes/push_swap.h"
#include <stdlib.h>
#include <string.h>

int	is_sorted(t_stack *stack)
{
	t_stack_node	*current;

	if (!stack || stack->size <= 1)
		return (1);
	current = stack->top;
	while (current && current->next)
	{
		if (current->rank > current->next->rank)
			return (0);
		current = current->next;
	}
	return (1);
}

static char	*word_dup(const char *start, int len)
{
	char	*word;
	int		i;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static int	count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static void	fill_split(char **result, const char *s, char c)
{
	int			i;
	const char	*start;
	int			len;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		start = s;
		len = 0;
		while (*s && *s != c)
		{
			s++;
			len++;
		}
		result[i++] = word_dup(start, len);
	}
	result[i] = NULL;
}

char	**ft_split(const char *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	fill_split(result, s, c);
	return (result);
}
