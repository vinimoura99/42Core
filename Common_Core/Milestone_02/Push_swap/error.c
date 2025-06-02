#include <unistd.h> // For write
#include <stdlib.h> // For exit
#include "push_swap.h"


void exit_error(void)
{
    write(2, "Error\n", 6); // Write "Error\n" to standard error
    exit(1);
}