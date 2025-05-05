/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:18:48 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/05 14:19:07 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int reverse_bits(unsigned int n) {
    unsigned int reversed = 0;
    int num_bits = sizeof(n) * 8;  // O número de bits do tipo unsigned int

    // Itera sobre todos os bits de n
    for (int i = 0; i < num_bits; i++) {
        reversed <<= 1;            // Desloca os bits de reversed para a esquerda
        reversed |= (n & 1);       // Copia o bit mais à direita de n para reversed
        n >>= 1;                   // Desloca os bits de n para a direita
    }

    return reversed;
}

int main() {
    unsigned int n = 5;  // Exemplo com o número 5
    unsigned int reversed = reverse_bits(n);
    printf("Original number: %u\n", n);
    printf("Reversed bits: %u\n", reversed);
    return 0;
}