#include <stdio.h>

char *ft_itoa(int n);

int main(void) {
    char *str = ft_itoa(42);
    printf("%s\n", str);
    return 0;
}
