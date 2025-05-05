/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:30:03 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/04/28 11:30:08 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putfloat(double num)
{
	int		len;
	int		int_part;
	double	frac_part;

	len = 0;
	int_part = (int)num;
	frac_part = num - int_part;
	len += ft_putnbr(int_part);
	len += ft_putchar('.');
	frac_part *= 1000000;
	len += ft_putnbr((int)frac_part);
	return (len);
}
