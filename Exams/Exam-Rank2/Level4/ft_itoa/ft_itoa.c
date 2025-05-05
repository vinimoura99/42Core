/* Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr); */

#include <stdlib.h>

char	*ft_itoa(int nbr)
{
    int		len = 0;
    int		temp = nbr;
    int		sign = 1;
    char	*str;

    // Handle negative numbers
    if (nbr < 0)
    {
        sign = -1;
        len++;
    }

    // Calculate the length of the number
    if (nbr == 0)
        len = 1;
    while (temp != 0)
    {
        temp /= 10;
        len++;
    }

    // Allocate memory for the string
    str = malloc((len + 1) * sizeof(char));
    if (!str)
        return (NULL);

    // Null-terminate the string
    str[len] = '\0';

    // Fill the string with digits
    if (nbr == 0)
        str[--len] = '0';
    while (nbr != 0)
    {
        if (nbr < 0)
            str[--len] = '0' - (nbr % 10);
        else
            str[--len] = '0' + (nbr % 10);
        nbr /= 10;
    }

    // Add the negative sign if needed
    if (sign == -1)
        str[0] = '-';

    return (str);
}