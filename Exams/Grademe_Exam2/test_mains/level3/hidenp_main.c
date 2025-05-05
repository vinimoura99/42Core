#include <stdio.h>

int hidenp(char *s1, char *s2);

int main(void) {
    int result = hidenp("hello", "hll");
    printf("Result: %d\n", result);
    return 0;
}
