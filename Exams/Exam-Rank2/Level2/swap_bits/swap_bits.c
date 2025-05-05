/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:20:12 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/05 14:20:31 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// Function to swap bits at positions p1 and p2 in an integer n
unsigned int swap_bits(unsigned int n, int p1, int p2) {
    // Extract the bits at positions p1 and p2
    int bit1 = (n >> p1) & 1;  // Extract bit at position p1
    int bit2 = (n >> p2) & 1;  // Extract bit at position p2
    
    // If the bits are different, swap them
    if (bit1 != bit2) {
        // Toggle the bits at positions p1 and p2 using XOR
        n ^= (1 << p1);  // Flip bit at p1
        n ^= (1 << p2);  // Flip bit at p2
    }
    
    return n;
}

int main() {
    unsigned int n = 13;  // Example number: 1101 in binary
    int p1 = 1, p2 = 3;   // Positions to swap (1 and 3)
    
    printf("Original number: %u\n", n);
    n = swap_bits(n, p1, p2);
    printf("After swapping bits at positions %d and %d: %u\n", p1, p2, n);
    
    return 0;
}
