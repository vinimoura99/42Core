/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:09:24 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/04 16:20:55 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    int idx = 0;

    while (s[idx])
    {
        int j = 0;
        while (reject[j])
        {
            if (s[idx] == reject[j])
                return idx;  // Retorna a posição da primeira ocorrência
            j++;
        }
        idx++;
    }
    return idx; // Nenhum caractere de reject foi encontrado
}

int main(int ac, char **av)
{
    if(ac == 3)
    {
        int resultado = ft_strcspn(av[1], av[2]);
        if(resultado != 0 && resultado != strlen(av[1]))
        {
            printf("A primeira ocorrência está na posição: %d\n", resultado);
        }
        else if (resultado == strlen(av[1]))
        {
            printf("Sem ocorrência\n");
        }
        else
        {
            printf("A primeira ocorrência está no início (posição 0)\n");
        }
    }
    else
    {
        printf("Uso: ./programa string1 string2\n");
    }
}