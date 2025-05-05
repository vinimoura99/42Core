/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:58:16 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/05 17:07:20 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_list_size.h"  // Inclusão do cabeçalho

int list_size(t_list *begin_list)
{
    int count = 0;

    // Verificando se a lista está vazia
    if (!begin_list) 
    {
        return 0;  // Lista vazia
    }

    while (begin_list) 
    {
        count++;  // Incrementa a contagem de nós
        begin_list = begin_list->next;  // Avança para o próximo nó
    }

    return count;  // Retorna o número de nós
}

int main(void)
{
    // Criando a lista
    t_list node3 = {(void *)"c", NULL};  // Último nó, aponta para NULL
    t_list node2 = {(void *)"b", &node3};  // Aponta para node3
    t_list node1 = {(void *)"a", &node2};  // Aponta para node2

    // Calculando o tamanho da lista
    printf("Tamanho da lista: %d\n", list_size(&node1));  // Esperado: 3

    return 0;
}


