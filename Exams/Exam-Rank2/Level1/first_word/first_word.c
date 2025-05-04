/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:46:27 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/03 10:53:18 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_first_word(char *str)
{
    int i = 0;

    while (str[i] ==  ' ' || str[i] == '\t')
    {
        i++;
    }
    while(str[i] != '\0' && str[i] != ' ')
    {
        write(1, &str[i], 1);
        i++;
    }

}

int main()
{
    char str[] = "  Olaeusou mundo";
    ft_first_word(str);
}