/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:45:14 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/05 16:45:16 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(const char *str, int str_base)
{
	int	i = 0;
	int	result = 0;
	int	sign = 1;

	// Lida com sinal negativo
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}

	while (str[i])
	{
		int digit;

		// Converte caractere para dígito numérico
		if (str[i] >= '0' && str[i] <= '9')
			digit = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			digit = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			digit = str[i] - 'A' + 10;
		else
			break;

		// Se o dígito não for válido para a base, para
		if (digit >= str_base)
			break;

		// Calcula valor acumulado
		result = result * str_base + digit;
		i++;
	}
	return (result * sign);
}
