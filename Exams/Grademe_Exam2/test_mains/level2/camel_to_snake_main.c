#include <stdio.h>

void camel_to_snake(char *str);

int main(void) {
    char str[] = "camelCase";
    camel_to_snake(str);
    printf("%s\n", str);
    return 0;
}
