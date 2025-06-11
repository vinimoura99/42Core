/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:40:01 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/11 12:21:40 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
✅ ft_isdigit:
	Verifica se o caractere c é um dígito ('0' a '9').
	Retorna: 1 se for dígito, 0 caso contrário.

✅ is_number_str :
	Verifica se a string representa um número inteiro válido
	(com sinal opcional).
	Retorna: 1 se for número válido, 0 caso contrário.

✅ ft_atol :
	Converte uma string para long, lidando com espaços e sinais (+/-).
	Inclui checagem de overflow para long e int.
	Chama exit_error() se ocorrer overflow.
	Retorna: o valor convertido como long.
*/

#include "../Includes/push_swap.h"
#include <limits.h>
#include <stdlib.h>

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_number_str(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL || *str == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (str[i] == '\0')
			return (0);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

// Atol
static long	parse_number(const char *str, int *i, int sign)
{
	long	result;

	result = 0;
	while (str[*i] && ft_isdigit(str[*i]))
	{
		if (sign == 1 && result > (LONG_MAX - (str[*i] - '0')) / 10)
			exit_error();
		if (sign == -1 && -(result) < (LONG_MIN + (str[*i] - '0')) / 10)
			exit_error();
		result = result * 10 + (str[(*i)++] - '0');
	}
	return (result * sign);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = parse_number(str, &i, sign);
	if (result > INT_MAX || result < INT_MIN)
		exit_error();
	return (result);
}
