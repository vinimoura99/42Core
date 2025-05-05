#include <stdio.h>

void rotone(char *str);

int main(void) {
    char str[] = "abc";
    rotone(str);
    printf("%s\n", str);
    return 0;
}
