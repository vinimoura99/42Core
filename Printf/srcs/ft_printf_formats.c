/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:29:43 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/04/28 11:29:47 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

int	ft_handle_format(char format, va_list args)
{
	char	*str;

	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
			return (ft_putstr("(null)"));
		return (ft_putstr(str));
	}
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else
		return (ft_extra_formats(format, args));
	return (0);
}

int	ft_extra_formats(char format, va_list args)
{
	char	*ptr;

	if (format == 'x')
		return (ft_putnbr_hex(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_putnbr_hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (format == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr == NULL)
			return (ft_putstr("(nil)"));
		return (ft_putptr(ptr));
	}
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_putnbr_hex(uintptr_t n, const char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_putnbr_hex(n / 16, base);
	len += ft_putchar(base[n % 16]);
	return (len);
}

int	ft_putptr(void *ptr)
{
	uintptr_t	address;
	int			len;

	address = (uintptr_t)ptr;
	len = 0;
	len += ft_putstr("0x");
	if (address == 0)
		len += ft_putchar('0');
	else
		len += ft_putnbr_hex(address, "0123456789abcdef");
	return (len);
}
