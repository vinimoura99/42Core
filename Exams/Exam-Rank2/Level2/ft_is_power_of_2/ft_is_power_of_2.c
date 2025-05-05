/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_power_of_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:02:24 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/05 12:18:37 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

//versao 1

/*int ft_is_power_of_2(unsigned int n)
{
    if (n <= 0) // Se n for menor ou igual a 0, não pode ser potência de 2
        return 0;

    // Vamos tentar calcular as potências de 2 de forma incremental
    int x = 0;
    while (pow(2, x) < n) // Enquanto 2^x for menor que n
    {
        x++; // Aumenta x
    }

    // Se 2^x for igual a n, então é potência de 2
    if (pow(2, x) == n)
        return 1;

    return 0;
}*/
//versao 2

/*int ft_is_power_of_2(unsigned int n)
{
    if (n == 0) // 0 não é potência de 2
        return 0;

    while (n % 2 == 0) // Enquanto for divisível por 2
        n = n / 2;

    if (n == 1) // Se sobrou 1, então era potência de 2
        return 1;
    else
        return 0;
}*/
int main()
{
    unsigned int test_numbers[] = {8, 16, 32, 10, 14, 25};

    for (int i = 0; i < 6; i++) {
        unsigned int n = test_numbers[i];

        if (ft_is_power_of_2(n) == 1)
            printf("%u é potência de 2\n", n);
        else
            printf("%u NÃO é potência de 2\n", n);
    }

    return 0;
}