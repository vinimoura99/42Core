/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:33:28 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/04 10:40:56 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{
    int idx = 0;

    while(s1[idx] != '\0' || s2[idx] != '\0')
    {
        s2[idx] = s1[idx];
        idx++;
    }
    return(s2);
}

/*int main(int ac, char **av)
{
    if(ac == 3)
    {
        printf("Argumentos iniciais: \n Argumento 1 -> %s \n Argumento 2 -> %s \n",av[1],av[2]);
        ft_strcpy(av[1],av[2]);
        printf("Argumentos finais: \n Argumento 1 -> %s \n Argumento 2 -> %s",av[1],av[2]);

    }
}*/