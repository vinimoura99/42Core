/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:55:11 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/03 11:05:56 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_fizzbuzz(int nb)
{
    if (nb < 0)
    {
        nb = -nb;
    }

    else if (nb > 9)
    {
        ft_fizzbuzz(nb /10);
        ft_fizzbuzz(nb % 10);
    }
    else
    {
        ft_putchar(nb + '0');
    }

}

int main()
{
    int i = 1;

    
    while(i <= 100)
    {
        if(i % 3 == 0 && i % 5 == 0)
        {
            write(1, "fizzbuzz", 8);
        }
        else if(i % 3 == 0)
        {
            write(1, "fizz", 4);
        }
        else if(i % 5 == 0)
        {
            write(1, "buzz", 4);
        }
        else
        {
            ft_fizzbuzz(i);
        }
        write(1, "\n", 1);
        i++;
    }
}