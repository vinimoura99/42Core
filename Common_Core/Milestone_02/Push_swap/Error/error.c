/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:37:29 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/11 12:08:11 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
✅ Esta função, exit_error, termina a execução do programa.
 O exit(1) indica que o programa terminou com um erro.
*/

#include "../Includes/push_swap.h"

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
