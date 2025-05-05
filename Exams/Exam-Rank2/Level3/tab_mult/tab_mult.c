/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:27:14 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/06 10:28:59 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *str)
{
    int result = 0;
    int i = 0;

    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}

void ft_putnbr(int nbr)
{
    char c;

    if (nbr >= 10)
        ft_putnbr(nbr / 10);
    c = (nbr % 10) + '0';
    write(1, &c, 1);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int num = ft_atoi(av[1]);
        int i = 1;
        
        while (i <= 9)
        {
            ft_putnbr(i);
            write(1, " x ", 3);
            ft_putnbr(num);
            write(1, " = ", 3);
            ft_putnbr(i * num);
            write(1, "\n", 1);
            i++;
        }
    }
    else
    {
        write(1, "\n", 1);
    }
    return 0;
}
