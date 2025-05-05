#include <stdio.h>

void tab_mult(int *tab, int size);

int main(void) {
    int tab[] = {1, 2, 3};
    tab_mult(tab, 3);
    for (int i = 0; i < 3; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
    return 0;
}
