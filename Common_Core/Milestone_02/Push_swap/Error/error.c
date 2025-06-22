/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:20:43 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/06 11:28:23 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // For write
#include <stdlib.h> // For exit
#include "../push_swap.h"


void exit_error(void)
{
    write(2, "Error\n", 6); // Write "Error\n" to standard error
    exit(1);
}