/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:43:40 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/04/28 12:43:43 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_handle_format(char format, va_list args);

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putnbr_long(long n);
int	ft_putnbr_hex(uintptr_t n, const char *base);
int	ft_putptr(void *ptr);
int	ft_extra_formats(char format, va_list args);

int	ft_putfloat(double num);		

#endif
