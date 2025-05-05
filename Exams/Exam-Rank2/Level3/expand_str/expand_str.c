/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:33:58 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/05 16:43:37 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Função pra saber se o caractere é espaço ou tab
int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

// Função principal
void	expand(char *str)
{
	int	i = 0;
	int	first_word = 1; // flag pra saber se estamos na primeira palavra

	// Pular todos os espaços/tabs do começo
	while (is_space(str[i]))
		i++;

	while (str[i])
	{
		// Se for o início de uma palavra
		if (!is_space(str[i]))
		{
			// Se NÃO for a primeira palavra, escreve 3 espaços antes
			if (!first_word)
				write(1, "   ", 3);
			// Escreve a palavra
			while (str[i] && !is_space(str[i]))
			{
				write(1, &str[i], 1);
				i++;
			}
			first_word = 0; // já imprimimos a primeira palavra
		}
		// Pula os espaços/tabs entre palavras
		while (is_space(str[i]))
			i++;
	}
	write(1, "\n", 1);
}

// Função main
int	main(int ac, char **av)
{
	if (ac == 2)
		expand(av[1]);
	else
		write(1, "\n", 1); // Se não tiver exatamente 1 argumento, só \n
	return (0);
}

