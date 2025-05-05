/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:23:50 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/05 14:23:57 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Função que verifica se a sequência de caracteres de "needle" está na string "haystack"
int wdmatch(char *haystack, char *needle)
{
    int i = 0;  // Índice para percorrer a string haystack
    int j = 0;  // Índice para percorrer a palavra needle

    // Percorre a string haystack até o final ou até encontrar a palavra needle
    while (haystack[i] != '\0' && needle[j] != '\0')
    {
        // Se o caractere de haystack for igual ao caractere de needle
        if (haystack[i] == needle[j])
        {
            j++;  // Avança para o próximo caractere de needle
        }
        i++;  // Avança para o próximo caractere de haystack
    }

    // Se percorremos toda a palavra needle, significa que ela está na ordem correta dentro de haystack
    if (needle[j] == '\0')
        return 1;  // Palavra encontrada

    return 0;  // Palavra não encontrada
}

int main(int argc, char **argv)
{
    if (argc == 3)  // Verifica se temos dois parâmetros
    {
        if (wdmatch(argv[1], argv[2]) == 1)  // Chama a função wdmatch
            write(1, "1\n", 2);  // Imprime 1 se a palavra foi encontrada
        else
            write(1, "0\n", 2);  // Imprime 0 se a palavra não foi encontrada
    }
    return 0;
}
