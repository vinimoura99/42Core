/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:09:48 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/05/04 15:09:58 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// This function returns the mirror of a letter (e.g., 'a' -> 'z', 'b' -> 'y')
char mirror_letter(char c) {
    if (c >= 'a' && c <= 'z') {
        return 'z' - (c - 'a'); // mirror for lowercase
    } else if (c >= 'A' && c <= 'Z') {
        return 'Z' - (c - 'A'); // mirror for uppercase
    } else {
        return c; // return the character unchanged if it's not a letter
    }
}

// This function applies the mirror to a whole string
void alpha_mirror(const char *input, char *output) {
    int i = 0;
    while (input[i] != '\0') {
        output[i] = mirror_letter(input[i]);
        i++;
    }
    output[i] = '\0'; // end the string
}

/*int main() {
    const char *original = "Hello, World!";
    char mirrored[100]; // make sure this is large enough for the result

    alpha_mirror(original, mirrored);

    printf("Original: %s\n", original);
    printf("Mirrored: %s\n", mirrored);

    return 0;
}*/
