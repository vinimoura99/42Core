/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:32:25 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/04 11:33:39 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
    if(ac == 2)
    {
        int idx = 0;
        while(av[1][idx])
        {
            if(av[1][idx] >= 'a' && av[1][idx] <= 'y')
            {
                av[1][idx] = av[1][idx] + 1;
            }
            else if(av[1][idx] >= 'A' && av[1][idx] <= 'y')
            {
                av[1][idx] = av[1][idx] + 13;
            }
            else if(av[1][idx] = 'z')
            {
                av[1][idx] = 'a';
            }
            else if(av[1][idx] = 'Z')
            {
                av[1][idx] = 'A';
            }
            write(1, &av[1][idx], 1);
            idx++;
        }
    }
    write(1, "\n", 1);
}