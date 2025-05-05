#include <stdio.h>

void epur_str(char *str);

int main(void) {
    char str[] = "   Hello   world   ";
    epur_str(str);
    printf("%s\n", str);
    return 0;
}
