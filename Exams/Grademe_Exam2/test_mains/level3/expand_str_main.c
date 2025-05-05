#include <stdio.h>

void expand_str(char *str);

int main(void) {
    char str[] = "Hello World!";
    expand_str(str);
    printf("%s\n", str);
    return 0;
}
