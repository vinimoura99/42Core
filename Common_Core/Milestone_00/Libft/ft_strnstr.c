/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:55:24 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/04/09 11:59:27 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *full, const char *search, size_t len)
{
	size_t	i;
	size_t	j;

	if (!search[0])
		return ((char *)full);
	i = 0;
	while (full[i] && i < len)
	{
		j = 0;
		while (full[i + j] && search[j]
			&& i + j < len && full[i + j] == search[j])
			j++;
		if (!search[j])
			return ((char *)(full + i));
		i++;
	}
	return (NULL);
}
