#include <stdio.h>

void inter(char *s1, char *s2);

int main(void) {
    char s1[] = "abc";
    char s2[] = "bcd";
    inter(s1, s2);
    printf("%s\n", s1);
    return 0;
}
