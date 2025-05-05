/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:19:40 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/06 11:15:19 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    putchar(char c)
{
    write(1, &c, 1);
}

int     isLower(int c)
{
    return (c >= 'a' && c <= 'z');
}

int     toUpper(int c)
{
    if (isLower(c))
        return (c - 32);
    return (c);
}

int     main(int ac, char **av)
{
    if (ac < 2)
    {
        putchar('\n');
        return (0);
    }
    int     i;

    i = 0;
    while (av[1][i])
    {
        if (av[1][i] == '_')
        {
            i++;
            putchar(toUpper(av[1][i]));
        }
        else 
            putchar(av[1][i]);
        i++;
    }
    putchar('\n');
    return (0);
}