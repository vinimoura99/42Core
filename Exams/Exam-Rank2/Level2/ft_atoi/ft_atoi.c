/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:57:14 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/04 15:57:16 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int my_atoi(char *str)
{
    int neg = 1;
    int res = 0;
    int i = 0;
    
    while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
    {
        i++;
    }
    if(str[i] == '+' || str[i] == '-')
    {
        if( str[i] == '-')
        {
            neg = -1;
        }
        i++;
    }
    while(str[i] >= '0'  && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return(res * neg);
}
