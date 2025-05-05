#include <stdio.h>

void flood_fill(char **tab, int x, int y, char new_color);

int main(void) {
    char *tab[] = {"....", "....", "...."};
    flood_fill(tab, 1, 1, 'X');
    return 0;
}
