#include <unistd.h>

void first_word(char *str)
{
    int i = 0;

    while (str[i] ==  ' ' || str[i] == '\t')
    {
        i++;
    }
    while(str[i] != '\0' && str[i] != ' ')
    {
        write(1, &str[i], 1);
        i++;
    }

}