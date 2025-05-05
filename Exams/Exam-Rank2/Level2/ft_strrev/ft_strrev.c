/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:33:52 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/05 11:47:30 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


int ft_strlen(char *str)
{
    int idx = 0;

        while(str[idx])
        {
            idx++;
        }
    return(idx);
}
char *ft_strrev(char *str) {
    int i = 0;
    int j = ft_strlen(str) - 1;
    char temp;

    while (i < j) {
        // Troca os caracteres nas posições i e j
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        i++;
        j--;
    }
    return str;
}

int main(int ac, char **av)
{
    if(ac == 2)
    {
        char *final = ft_strrev(av[1]);
        printf("Palavra invertida : %s \n",final);
    }
}
