/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:42:52 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/04 10:45:50 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
    int idx;

    idx = 0;
    while(str[idx] != '\0')
    {
        idx++;
    }
    return(idx);
}

int main(int ac, char **av)
{
    if(ac == 2)
    {
        int resultado = ft_strlen(av[1]);
        printf("Total da palavra %s e %d", av[1], resultado);
    }
}