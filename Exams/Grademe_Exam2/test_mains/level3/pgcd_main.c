#include <stdio.h>

int pgcd(int a, int b);

int main(void) {
    int result = pgcd(4, 5);
    printf("PGCD: %d\n", result);
    return 0;
}
