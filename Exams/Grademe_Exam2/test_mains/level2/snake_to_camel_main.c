#include <stdio.h>

void snake_to_camel(char *str);

int main(void) {
    char str[] = "snake_case_example";
    snake_to_camel(str);
    printf("%s\n", str);
    return 0;
}
