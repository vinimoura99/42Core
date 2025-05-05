/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:26:05 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/06 10:26:12 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Função para verificar se um caractere é uma letra
int is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Função para capitalizar as palavras
void str_capitalize(char *str) {
    int i = 0;
    int start = 0;
    
    while (str[i]) {
        // Se encontramos um espaço ou o fim da string, processamos a palavra
        if (str[i] == ' ' || str[i] == '\t' || str[i + 1] == '\0') {
            // Transformar a primeira letra da palavra em maiúscula
            if (i > start && is_letter(str[start])) {
                str[start] = (str[start] >= 'a' && str[start] <= 'z') ? str[start] - 32 : str[start];  // Maiúscula
            }

            // Tornar as outras letras da palavra em minúscula
            int j = start + 1;
            while (j < i && str[j]) {
                if (is_letter(str[j]) && str[j] >= 'A' && str[j] <= 'Z') {
                    str[j] += 32;  // Minúscula
                }
                j++;
            }

            // Imprimir a palavra processada
            write(1, str + start, i - start);
            
            // Se não for o último, adicionar um espaço
            if (str[i]) write(1, " ", 1);
            start = i + 1;
        }
        i++;
    }
}

int main(int ac, char **av) {
    if (ac == 1) {
        write(1, "\n", 1);  // Se não tiver argumentos, imprime uma nova linha
    } else {
        int i = 1;
        while (i < ac) {
            str_capitalize(av[i]);
            i++;
        }
    }
    write(1, "\n", 1);  // Nova linha no final
    return 0;
}
