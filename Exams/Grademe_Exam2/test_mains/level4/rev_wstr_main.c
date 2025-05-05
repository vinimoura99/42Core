#include <stdio.h>

void rev_wstr(char **tab);

int main(void) {
    char *tab[] = {"hello", "world"};
    rev_wstr(tab);
    return 0;
}
