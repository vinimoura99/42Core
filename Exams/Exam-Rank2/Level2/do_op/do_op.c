/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:28:48 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/04 15:54:57 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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


int main(int ac, char **av)
{
    if (ac == 4)
    {   
        char op = *av[2];
        int res;

        int a = my_atoi(av[1]);
        int b = my_atoi(av[3]);

        if(op == '+')
            res = a + b;
        else if(op == '-')
            res = a - b;
        else if(op == '*')
            res = a * b;
        else if(op == '/')
        {
            if (b == 0)
            {
                printf("Erro: divisao por zero\n");
                return (1);
            }
            res = a / b;
        }
        else
        {
            printf("Operador invalido\n");
            return (1);
        }

        printf("resultado = %d\n", res);
    }
    else
    {
        printf("Uso: ./programa numero1 operador numero2\n");
    }

    return 0;
}
