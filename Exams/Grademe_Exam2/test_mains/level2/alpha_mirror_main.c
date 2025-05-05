#include <stdio.h>

void alpha_mirror(char *str);

int main(void) {
    char str[] = "abc";
    alpha_mirror(str);
    printf("%s\n", str);
    return 0;
}
