/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:19:06 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/04 17:19:36 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strpbrk(const char *s1, const char *s2)
{
    int i = 0;
    while (s1[i])
    {
        int j = 0;
        while (s2[j])
        {
            if (s1[i] == s2[j])
                return (char *)(s1 + i);  // Retorna ponteiro para s1[i]
            j++;
        }
        i++;
    }
    return NULL;
}

/*int main()
{
    const char *texto = "abcdef";
    const char *busca = "xyzc";

    char *res = ft_strpbrk(texto, busca);

    if (res)
        printf("Primeiro caractere encontrado: %c\n", *res);  // Deve imprimir 'c'
    else
        printf("Nenhum caractere encontrado.\n");

    return 0;
}*/