/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:08:06 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/04 11:17:02 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char    str_rev(char *str)
{
    int idx = 0;
    while(str[idx])
    {
        idx++;
    }
    while(idx > 0)
    {
        idx--;
        write(1, &str[idx], 1);
        
    }
    return(*str);

}

int main(int ac, char **av)
{
    if(ac == 2)
    {
        str_rev(av[1]);
    }
    write(1, "\n", 1);
}