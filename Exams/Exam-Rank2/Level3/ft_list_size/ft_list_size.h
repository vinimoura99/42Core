/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:59:03 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/05 17:06:45 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_SIZE_H
#define LIST_SIZE_H

typedef struct s_list
{
    void *data;
    struct s_list *next;
} t_list;

int list_size(t_list *begin_list);

#endif
