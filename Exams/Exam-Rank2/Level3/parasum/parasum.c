/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parasum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:29:57 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/06 10:04:44 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putnbr(int n)
{
    if (n >= 10)
        ft_putnbr(n / 10);
    char digit = n % 10 + '0';
    write(1, &digit, 1);
}

int main(int ac, char **av)
{
    (void)av; // silence unused variable warning
    ft_putnbr(ac - 1); // argument count excluding program name
    write(1, "\n", 1);
    return 0;
}