/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:26:19 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/04 10:30:30 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
    int idx = 0;
    while(str[idx] != '\0')
    {
        write(1, &str[idx], 1);
        idx++;
    }
}

int main(int ac, char **av)
{
    if(ac == 2)
    {
        ft_putstr(av[1]);
    }
}