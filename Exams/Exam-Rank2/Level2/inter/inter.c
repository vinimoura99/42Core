/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:48:20 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/05 11:59:44 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	int j;
	int tab[256] = {0};

	if (argc == 3)
	{
		while (argv[1][i])
		{
			j = 0;
			while (argv[2][j])
			{
				if (argv[1][i] == argv[2][j])
				{
					unsigned char c = argv[1][i];
					if (tab[c] == 0)
					{
						tab[c] = 1;
						write(1, &c, 1);
						break; // já achou em argv[2], não precisa continuar
					}
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}
