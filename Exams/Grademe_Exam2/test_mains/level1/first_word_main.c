// test_mains/level1/first_word_main.c
#include <unistd.h>

// Declare the function from first_word.c
void first_word(char *str);

int main(void)
{
    first_word("  This is a test\n");
    write(1, "\n", 1);
    return 0;
}