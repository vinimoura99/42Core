/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:15:44 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/06 10:16:12 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // para usar write

// Converte string para inteiro
int ft_atoi(char *str)
{
    int i = 0;
    int res = 0;

    // Enquanto o caractere for um dígito ('0' a '9')
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0'); // conversão ASCII para número
        i++;
    }
    return res;
}

// Imprime número em hexadecimal (recursivamente)
void put_hex(unsigned int n)
{
    char *hex = "0123456789abcdef";

    if (n >= 16)
        put_hex(n / 16); // Chamada recursiva para imprimir os dígitos mais à esquerda

    char c = hex[n % 16]; // Obtém o dígito hexadecimal atual
    write(1, &c, 1);      // Imprime o dígito
}

// Função principal
int main(int ac, char **av)
{
    if (ac == 2) // Verifica se foi passado exatamente 1 argumento
    {
        int n = ft_atoi(av[1]); // Converte argumento para inteiro
        put_hex(n);             // Imprime número em hexadecimal
    }

    write(1, "\n", 1); // Imprime nova linha em qualquer caso
    return 0;
}
