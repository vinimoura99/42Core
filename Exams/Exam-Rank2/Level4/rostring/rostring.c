/* Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$> */

#include <unistd.h>

void rostring(char *str)
{
    int i = 0;
    int start = 0;
    int end = 0;

    // Skip leading spaces and tabs
    while (str[i] == ' ' || str[i] == '\t')
        i++;

    // Mark the start of the first word
    start = i;

    // Find the end of the first word
    while (str[i] && str[i] != ' ' && str[i] != '\t')
        i++;
    end = i;

    // Skip spaces and tabs after the first word
    while (str[i] == ' ' || str[i] == '\t')
        i++;

    // Print the rest of the string (words after the first word)
    while (str[i])
    {
        if (str[i] != ' ' && str[i] != '\t')
        {
            // Print the current word
            while (str[i] && str[i] != ' ' && str[i] != '\t')
                write(1, &str[i++], 1);

            // Print a space if there are more words
            if (str[i])
                write(1, " ", 1);
        }
        else
            i++;
    }

    // Print the first word at the end
    if (start < end)
    {
        if (i > end) // Print a space before the first word if there were other words
            write(1, " ", 1);
        while (start < end)
            write(1, &str[start++], 1);
    }
}

int main(int ac, char **av)
{
    if (ac > 1)
        rostring(av[1]);
    write(1, "\n", 1);
    return 0;
}