/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 08:51:24 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/06 08:55:36 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int *ft_range(int min, int max)
{
    int *arr;
    int i;
    int size;

    if (min > max)
        return NULL;
    size = max - min + 1;
    arr = (int *)malloc(sizeof(int) * size);
    if (!arr)
        return NULL;
    i = 0;
    while (i < size)
    {
        arr[i] = min + i;
        i++;
    }
    return arr;
}


int main(void)
{
    int min = 4;
    int max = 3;
    int *range = ft_range(min, max);
    int size = max - min + 1;

    if (!range)
    {
        printf("Returned NULL\n");
        return 1;
    }

    for (int i = 0; i < size; i++)
        printf("%d ", range[i]);
    printf("\n");

    free(range);
    return 0;
}