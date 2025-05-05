/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:49:28 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/05 13:07:07 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


int     ft_strlen(char *str)
{
    int idx = 0;
    while(str[idx])
    {
        idx++;
    }
    return(idx);
}
int is_delimiter(char c)
{
    
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f')
    {
        return 1; 
    }
    return 0; 
}
void find(char *str)
{
    int idx = 0;
    int start = 0;

    // Calcula o tamanho da string
    idx = ft_strlen(str);

    // Caso tenha espaços no final, retrocede até o primeiro caractere não delimitador
    while (idx > 0 && is_delimiter(str[idx - 1]))
    {
        idx--;
    }

    // Salvar o índice de início da última palavra
    start = idx;

    // Continuar retrocedendo até encontrar o primeiro delimitador
    while (idx > 0 && !is_delimiter(str[idx - 1]))
    {
        idx--;
    }

    // Escrever a última palavra
    write(1, &str[idx], start - idx);  // Escreve a palavra entre os índices
    write(1, "\n", 1);  // Adiciona uma nova linha após a palavra
}

int main(int ac, char **av)
{
    if(ac == 2)
    {
        find(av[1]);
    }
}