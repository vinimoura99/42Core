/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:31:19 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/05 16:33:06 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	epur_str(char *str)
{
	int	i = 0;
	int	space = 0;

	// Pula espaços/tabs iniciais
	while (is_space(str[i]))
		i++;

	while (str[i])
	{
		if (is_space(str[i]))
			space = 1;
		else
		{
			if (space)
			{
				ft_putchar(' ');
				space = 0;
			}
			ft_putchar(str[i]);
		}
		i++;
	}
}