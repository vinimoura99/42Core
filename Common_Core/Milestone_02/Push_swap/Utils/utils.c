/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:48:40 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/06 12:48:42 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

int is_number_str(const char *str)
{
    int i = 0;

    if (str == NULL || *str == '\0')
        return (0);
    if (str[i] == '-' || str[i] == '+')
    {
        i++;
        if (str[i] == '\0')
            return (0);
    }
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

long ft_atol(const char *str)
{
    long	result = 0;
    int		sign = 1;
    int		i = 0;

    while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (ft_isdigit(str[i]))
    {
        if (sign == 1 && result > (LONG_MAX - (str[i] - '0')) / 10)
            exit_error();
        if (sign == -1 && result < (LONG_MIN + (str[i] - '0')) / 10)
            exit_error();

        result = result * 10 + (str[i] - '0');
        i++;
    }
    result *= sign;
    if (result > INT_MAX || result < INT_MIN)
        exit_error();
    return (result);
}

int is_sorted(t_stack *stack)
{
    t_stack_node *current;

    if (!stack || stack->size <= 1)
        return (1);
    current = stack->top;
    while (current && current->next)
    {
        if (current->rank > current->next->rank)
            return (0);
        current = current->next;
    }
    return (1);
}
