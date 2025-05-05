/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:16:55 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/06 10:25:23 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Função para verificar se um caractere é uma letra
int is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Função para capitalizar a última letra de cada palavra
void rstr_capitalize(char *str) {
    int i = 0;
    int start = 0;
    
    while (str[i]) {
        // Se encontramos um espaço ou o fim da string, processamos a palavra
        if (str[i] == ' ' || str[i] == '\t' || str[i + 1] == '\0') {
            // Encontrar a última letra da palavra
            int last_letter = i - 1;
            while (last_letter >= start && !is_letter(str[last_letter])) {
                last_letter--;
            }

            // Tornar a última letra maiúscula
            if (last_letter >= start) {
                str[last_letter] = (str[last_letter] >= 'a' && str[last_letter] <= 'z') ?
                                    str[last_letter] - 32 : str[last_letter];  // Maiúscula
            }

            // Tornar as outras letras minúsculas
            for (int j = start; j < i; j++) {
                if (is_letter(str[j])) {
                    str[j] = (str[j] >= 'A' && str[j] <= 'Z') ?
                             str[j] + 32 : str[j];  // Minúscula
                }
            }
            start = i + 1;
        }
        i++;
    }

    write(1, str, i);  // Imprime a string processada
}

int main(int ac, char **av) {
    if (ac == 1) {
        write(1, "\n", 1);  // Se não tiver argumentos, imprime uma nova linha
    } else {
        for (int i = 1; i < ac; i++) {
            rstr_capitalize(av[i]);
            write(1, " ", 1);  // Espaço entre as palavras
        }
        write(1, "\n", 1);  // Nova linha no final
    }

    return 0;
}
