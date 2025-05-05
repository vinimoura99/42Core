/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:50:34 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/05 13:50:49 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void print_bits(unsigned int n) {
    for (int i = 31; i >= 0; i--) {  // Laço de 31 até 0
        if (n & (1 << i))  // Verifica se o bit na posição i é 1 ou 0
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

int main() {
    unsigned int num = 5;  // Teste com o número 5
    print_bits(num);  // Chama a função para imprimir os bits de 5
    return 0;
}