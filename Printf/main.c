/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:43:43 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/04/30 14:44:14 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>  // Para printf (para comparação)
#include "ft_printf.h"  // Inclua seu cabeçalho ft_printf.h

int main() {
    // Teste de impressão de string
    char *str = "Olá, mundo!";
    int ret1 = ft_printf("String: %s\n", str);
    int ret2 = printf("String: %s\n", str);
    printf("ft_printf retornou: %d, printf retornou: %d\n", ret1, ret2);

    // Teste de impressão de inteiro
    int num = 42;
    ret1 = ft_printf("Número: %d\n", num);
    ret2 = printf("Número: %d\n", num);
    printf("ft_printf retornou: %d, printf retornou: %d\n", ret1, ret2);

    // Teste de impressão de caractere
    char ch = 'A';
    ret1 = ft_printf("Caractere: %c\n", ch);
    ret2 = printf("Caractere: %c\n", ch);
    printf("ft_printf retornou: %d, printf retornou: %d\n", ret1, ret2);

    // Teste de impressão de número hexadecimal
    unsigned int hex_num = 255;
    ret1 = ft_printf("Hexadecimal: %x\n", hex_num);
    ret2 = printf("Hexadecimal: %x\n", hex_num);
    printf("ft_printf retornou: %d, printf retornou: %d\n", ret1, ret2);

    // Teste de impressão de ponteiro
    int *ptr = &num;
    ret1 = ft_printf("Ponteiro: %p\n", (void *)ptr);
    ret2 = printf("Ponteiro: %p\n", (void *)ptr);
    printf("ft_printf retornou: %d, printf retornou: %d\n", ret1, ret2);

    // Teste de impressão de número inteiro negativo
    int neg_num = -42;
    ret1 = ft_printf("Número negativo: %d\n", neg_num);
    ret2 = printf("Número negativo: %d\n", neg_num);
    printf("ft_printf retornou: %d, printf retornou: %d\n", ret1, ret2);

    return 0;
}
