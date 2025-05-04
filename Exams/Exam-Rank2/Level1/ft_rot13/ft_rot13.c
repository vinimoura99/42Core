/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot13.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:26:02 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/04 11:31:42 by vmoura-d         ###   ########.fr       */
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
            if(av[1][idx] >= 'a' && av[1][idx] <= 'm')
            {
                av[1][idx] = av[1][idx] + 13;
            }
            else if(av[1][idx] >= 'n' && av[1][idx] <= 'z')
            {
                av[1][idx] = av[1][idx] - 13;
            }
            else if(av[1][idx] >= 'A' && av[1][idx] <= 'M')
            {
                av[1][idx] = av[1][idx] + 13;
            }
            else if(av[1][idx] >= 'N' && av[1][idx] <= 'Z')
            {
                av[1][idx] = av[1][idx] - 13;
            }
            write(1, &av[1][idx], 1);
            idx++;
        }
    }
    write(1, "\n", 1);
}