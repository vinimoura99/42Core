/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 08:57:55 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/06 08:58:24 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include<stdio.h>

int *ft_rrange(int start, int end)
{
    int size;
    int *arr;
    int i = 0;

    if (start > end)
        size = start - end + 1;
    else
        size = end - start + 1;

    arr = (int *)malloc(sizeof(int) * size);
    if (!arr)
        return NULL;

    while (i < size)
    {
        arr[i] = end;
        if (start > end)
            end++;
        else
            end--;
        i++;
    }

    return arr;
}
int main(void)
{
    int start = 1;
    int end = 3;
    int size;
    int *range;
    int i;

    if (start > end)
        size = start - end + 1;
    else
        size = end - start + 1;

    range = ft_rrange(start, end);
    if (!range)
    {
        printf("Returned NULL\n");
        return 1;
    }

    i = 0;
    while (i < size)
    {
        printf("%d ", range[i]);
        i++;
    }
    printf("\n");

    free(range);
    return 0;
}