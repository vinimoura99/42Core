/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_and_replace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:35:36 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/04 11:44:20 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac == 4 && av[2][1] == '\0' && av[3][1] == '\0')
	{
		int i = 0;
		char from = av[2][0];
		char to = av[3][0];

		while (av[1][i])
		{
			if (av[1][i] == from)
				write(1, &to, 1);
			else
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}