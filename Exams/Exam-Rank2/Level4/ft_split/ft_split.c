/* Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str); */

#include <stdlib.h>

// Helper function to check if a character is a delimiter (space, tab, or newline)
int is_delimiter(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

// Helper function to count the number of words in the string
int count_words(char *str)
{
    int count = 0;
    int in_word = 0;

    while (*str)
    {
        if (!is_delimiter(*str) && in_word == 0)
        {
            in_word = 1;
            count++;
        }
        else if (is_delimiter(*str))
        {
            in_word = 0;
        }
        str++;
    }
    return count;
}

// Helper function to allocate and copy a word
char *allocate_word(char *start, char *end)
{
    int len = end - start;
    char *word = malloc((len + 1) * sizeof(char));
    int i = 0;

    if (!word)
        return NULL;
    while (start < end)
    {
        word[i++] = *start++;
    }
    word[i] = '\0';
    return word;
}

// Main function to split the string into words
char **ft_split(char *str)
{
    char **result;
    int word_count = count_words(str);
    int i = 0;
    char *start = NULL;

    result = malloc((word_count + 1) * sizeof(char *));
    if (!result)
        return NULL;

    while (*str)
    {
        if (!is_delimiter(*str) && !start)
        {
            start = str; // Mark the beginning of a word
        }
        else if (is_delimiter(*str) && start)
        {
            result[i++] = allocate_word(start, str); // Allocate and store the word
            start = NULL;
        }
        str++;
    }
    if (start) // Handle the last word
        result[i++] = allocate_word(start, str);

    result[i] = NULL; // Null-terminate the array
    return result;
}