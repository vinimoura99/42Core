/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:08:07 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/05 13:14:44 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int max(int* tab, unsigned int len)
{
    // Caso o array seja vazio, retorna 0
    if (len == 0)
    {
        return 0;
    }

    // Inicializa o maior valor com o primeiro elemento do array
    int max_value = tab[0];

    // Percorre o array a partir do segundo elemento
    for (unsigned int i = 1; i < len; i++)
    {
        if (tab[i] > max_value)
        {
            max_value = tab[i];  // Atualiza o maior valor encontrado
        }
    }

    return max_value;  // Retorna o maior valor encontrado
}

int main()
{
    int tab[] = {3, 5, 7, 2, 8, 1};
    unsigned int len = sizeof(tab) / sizeof(tab[0]);

    int result = max(tab, len);
    printf("O maior valor do array é: %d\n", result);

    return 0;
}