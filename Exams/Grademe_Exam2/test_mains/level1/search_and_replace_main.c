#include <stdio.h>

void search_and_replace(char *str, char old, char new);

int main(void) {
    char str[] = "hello";
    search_and_replace(str, 'l', 'x');
    printf("%s\n", str);
    return 0;
}
