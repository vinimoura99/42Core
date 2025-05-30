/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:22:54 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/05 15:23:24 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // For write

void	ft_small_putnbr(int nbr)
{
	char	digit_char;

	if (nbr > 9)
	{
		ft_small_putnbr(nbr / 10);
		ft_small_putnbr(nbr % 10);
	}
	else
	{
		digit_char = nbr + '0';
		write(1, &digit_char, 1);
	}
}

int	ft_is_prime(int nbr)
{
	int	check;

	check = 2;
	if (nbr <= 1)
		return (0);
	while (check < nbr)
	{
		if ((nbr % check) == 0)
			return (0);
		check++;
	}
	return (1);
}

int	ft_short_atoi(char *str)
{
	int	idx;
	int	result;

	idx = 0;
	result = 0;
	while (str[idx] != '\0')
	{
		result *= 10;
		result += str[idx] - '0';
		idx++;
	}
	return (result);
}

int	ft_add_prime_sum(int nbr)
{
	int	idx;
	int	sum;

	idx = 2;
	sum = 0;
	if (nbr <= 0)
		return (0);
	while (idx <= nbr)
	{
		if (ft_is_prime(idx))
			sum += idx;
		idx++;
	}
	return (sum);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_small_putnbr(ft_add_prime_sum(ft_short_atoi((argv[1]))));
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}