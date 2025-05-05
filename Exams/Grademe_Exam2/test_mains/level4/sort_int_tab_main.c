#include <stdio.h>

void sort_int_tab(int *tab, int size);

int main(void) {
    int tab[] = {3, 1, 2};
    sort_int_tab(tab, 3);
    for (int i = 0; i < 3; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
    return 0;
}
