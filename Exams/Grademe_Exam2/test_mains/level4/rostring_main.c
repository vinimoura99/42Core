#include <stdio.h>

void rostring(char *str);

int main(void) {
    char str[] = "hello world";
    rostring(str);
    printf("%s\n", str);
    return 0;
}
