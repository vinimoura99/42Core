/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repeat_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:59:59 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/04 11:03:42 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		while (argv[1][i])
		{
			char c = argv[1][i];
			int repeat = 1;

			if (c >= 'a' && c <= 'z')
				repeat = c - 'a' + 1;
			else if (c >= 'A' && c <= 'Z')
				repeat = c - 'A' + 1;

			while (repeat--)
				write(1, &c, 1);

			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
