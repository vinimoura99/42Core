#include <stdio.h>

void rot_13(char *str);

int main(void) {
    char str[] = "Hello World!";
    rot_13(str);
    printf("%s\n", str);
    return 0;
}
