/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:10:14 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/04 15:28:09 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Retorna 1 se o caractere for letra maiúscula (A-Z), senão 0
int upper(char c) {
    return (c >= 'A' && c <= 'Z');
}

// Converte letra maiúscula para minúscula. Se não for, retorna o próprio caractere.
char lower(char c) {
    if (upper(c)) {
        return c + ('a' - 'A'); // diferença entre 'A' e 'a' na tabela ASCII
    }
    return c;
}

// Converte camelCase para snake_case
void camel_to_snake(const char *input, char *output) {
    int i = 0, j = 0;

    while (input[i] != '\0') 
    { 
        if (!upper(input[i]))
        {
            // Se for minúscula ou outro caractere, copia direto
            output[j++] = input[i];
        }
        else
        {
            // Se for letra maiúscula, adiciona '_' e a letra minúscula
            output[j++] = '_';
            output[j++] = lower(input[i]);
        } 
       
        i++;
    }

    output[j] = '\0'; // Finaliza a string
}

int main() {

    const char *camel = "hereIsACamelCaseWord";
    char snake[100];
    int idx = 0;

    camel_to_snake(camel, snake);
    while(snake[idx])
    {
        idx++;
    }
    write(1, &snake, idx);
    return 0;
}