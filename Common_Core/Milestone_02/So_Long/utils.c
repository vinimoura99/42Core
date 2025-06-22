/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:39:50 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/22 18:41:14 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "game.h"

static int ft_putchar(char c)
{
    return write(1, &c, 1);
}

static int ft_putstr(char *s)
{
    int i = 0;
    if (!s)
        s = "(null)";
    while (s[i])
        ft_putchar(s[i++]);
    return i;
}

static int ft_putnbr(int n)
{
    int count = 0;
    long nb = n;

    if (nb < 0)
    {
        count += ft_putchar('-');
        nb = -nb;
    }
    if (nb >= 10)
        count += ft_putnbr(nb / 10);
    count += ft_putchar((nb % 10) + '0');
    return count;
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int i = 0;
    int count = 0;

    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
                count += ft_putchar((char)va_arg(args, int));
            else if (format[i] == 's')
                count += ft_putstr(va_arg(args, char *));
            else if (format[i] == 'd')
                count += ft_putnbr(va_arg(args, int));
            else if (format[i] == '%')
                count += ft_putchar('%');
            else
                count += ft_putchar(format[i]); // imprime o que vier depois de % se não reconhecido
        }
        else
            count += ft_putchar(format[i]);
        i++;
    }
    va_end(args);
    return count;
}

