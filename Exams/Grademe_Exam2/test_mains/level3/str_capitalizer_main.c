#include <stdio.h>

void str_capitalizer(char *str);

int main(void) {
    char str[] = "hello world";
    str_capitalizer(str);
    printf("%s\n", str);
    return 0;
}
