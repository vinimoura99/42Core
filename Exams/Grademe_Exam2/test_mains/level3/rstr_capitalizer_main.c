#include <stdio.h>

void rstr_capitalizer(char *str);

int main(void) {
    char str[] = "hello world";
    rstr_capitalizer(str);
    printf("%s\n", str);
    return 0;
}
