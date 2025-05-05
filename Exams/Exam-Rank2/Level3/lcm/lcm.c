/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:26:33 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/06 09:28:47 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// Function to compute GCD (Greatest Common Divisor)
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute LCM (Least Common Multiple)
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    int a = 12, b = 15;
    printf("LCM of %d and %d is: %d\n", a, b, lcm(a, b));
    return 0;
}
