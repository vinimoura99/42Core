/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:28:55 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/04 16:36:10 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>

char    *ft_strdup(char *src)
{
    int idx = 0;
    int i = 0;
    while(src[idx])
    {
        idx++;
    }

    char *copy = malloc(idx + 1);

    if(!copy)
        return(NULL);

    while(src[i])
    {
        copy[i] = src[i];
        i++;
    }
    return(copy);
}

/*int main()
{
    char str[] = "Ola mundo";
    char *resultado = ft_strdup(str);
    printf("A palavra copiada foi %s",resultado);
}*/