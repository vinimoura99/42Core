/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:00:56 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/06 09:24:30 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
int     ft_strlen(char *str)
{
    int idx = 0;
    while(str[idx])
    {
        idx++;
    }
    return(idx);
}
char    find_hidden(char *str, char *str2)
{
    int size = ft_strlen(str);
    int idx = 0;
    int idx2 = 0;
    int counter = 0;
    

    while(str[idx2])
    {
        idx = 0;
        while(str2[idx])
        {
            if(str[idx2] == str2[idx])
            {
                counter = counter + 1;
                break;
            }
            idx++;
        }
        idx2++;
    }
    if(counter == size)
    {
        return(1);
    }
    else
        return(0);
}

int main(int ac, char **av)
{
    if(ac == 3)
    {
        int res = find_hidden(av[1],av[2]);
        printf("%d \n",res);
        
    }
}