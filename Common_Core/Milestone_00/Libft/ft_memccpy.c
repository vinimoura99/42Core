/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:43:23 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/04/10 13:43:27 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	if (n == 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
		if (((const unsigned char *)src)[i] == (unsigned char)c)
		{
			return ((unsigned char *)dst + i + 1);
		}
		i++;
	}
	return (NULL);
}


