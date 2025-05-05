#include <stdio.h>

void ulstr(char *str);

int main(void) {
    char str[] = "hello world";
    ulstr(str);
    printf("%s\n", str);
    return 0;
}
