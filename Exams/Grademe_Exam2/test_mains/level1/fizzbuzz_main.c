#include <stdio.h>

void fizzbuzz(int n);

int main(void) {
    for (int i = 1; i <= 100; i++) {
        fizzbuzz(i);
        printf("\n");
    }
    return 0;
}
