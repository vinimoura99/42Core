/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:49:42 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/04 10:58:55 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
    int tmp;
    tmp = *a;

    *a = *b;
    *b = tmp;
}

int main()
{
    int *val;
    int *val2;
    int x = 10;
    int y = 20;

    val = &x;
    val2 = &y;

    printf("1 valor : %d \n 2 valor %d \n",x,y);
    ft_swap(val,val2);
    printf("\n Apos troca : \n 1 valor : %d \n 2 valor %d \n",*val,*val2);
}