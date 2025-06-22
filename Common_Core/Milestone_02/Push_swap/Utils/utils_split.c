/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:48:36 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/06 13:05:56 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static size_t	count_words(const char *str, char delimiter)
{
	size_t	count = 0;
	int		in_word = 0;

	while (*str)
	{
		if (*str != delimiter && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*str == delimiter)
			in_word = 0;
		str++;
	}
	return (count);
}

static char	*word_dup(const char *start, size_t len)
{
	char	*word = malloc(len + 1);
	if (!word)
		return (NULL);
	for (size_t i = 0; i < len; i++)
		word[i] = start[i];
	word[len] = '\0';
	return (word);
}

char	**ft_split(const char *s, char delimiter)
{
	size_t	words = count_words(s, delimiter);
	char	**result = malloc((words + 1) * sizeof(char *));
	size_t	i = 0;
	const char	*start;

	if (!s || !result)
		return (NULL);
	while (*s)
	{
		if (*s != delimiter)
		{
			start = s;
			while (*s && *s != delimiter)
				s++;
			result[i++] = word_dup(start, s - start);
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}
void	parse_arguments_split(char **split, t_stack *stack)
{
	int		i;
	long	num;

	i = 0;
	while (split[i])
	{
		if (!is_number_str(split[i]))
			exit_error();
		num = ft_atol(split[i]);
		if (num > INT_MAX || num < INT_MIN)
			exit_error();
		add_value_to_bottom(stack, (int)num);
		i++;
	}
}

void	free_split(char **split)
{
	int	i = 0;

	while (split && split[i])
		free(split[i++]);
	free(split);
}

