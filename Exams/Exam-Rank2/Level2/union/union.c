/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:23:12 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/05 14:23:13 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Função que vai verificar se o caractere já foi impresso
// Se o caractere já foi impresso, ele retorna 1 (já foi), senão retorna 0
int já_foi_impressa(char *str, char c, int até_aqui)
{
    for (int i = 0; i < até_aqui; i++)
    {
        if (str[i] == c)  // Se o caractere já apareceu antes, retornamos 1
            return 1;  // Caractere já apareceu antes
    }
    return 0;  // Caractere ainda não apareceu
}

// Função que vai unir as duas strings e imprimir caracteres únicos
void ft_union(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    
    // Passando pela primeira string (s1)
    while (s1[i] != '\0')  // Enquanto não chegar ao final da string
    {
        // Verificando se o caractere ainda não foi impresso
        if (já_foi_impressa(s1, s1[i], i) == 0)  // 0 significa que o caractere é único
        {
            write(1, &s1[i], 1);  // Imprime o caractere
        }
        i++;  // Vai para o próximo caractere
    }

    // Passando pela segunda string (s2)
    while (s2[j] != '\0')  // Enquanto não chegar ao final da string
    {
        // Verificando se o caractere de s2 não apareceu em s1 e ainda não foi impresso
        if (já_foi_impressa(s1, s2[j], i) == 0 && já_foi_impressa(s2, s2[j], j) == 0)
        {
            write(1, &s2[j], 1);  // Imprime o caractere
        }
        j++;  // Vai para o próximo caractere
    }
}

int main(int argc, char **argv)
{
    if (argc == 3)  // Se passarmos duas strings
    {
        ft_union(argv[1], argv[2]);  // Chama a função ft_union com as duas strings
    }
    write(1, "\n", 1);  // No final, imprime uma nova linha
    return (0);
}
