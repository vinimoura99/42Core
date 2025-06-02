#include "push_swap.h"

// Checks if a character is a digit
static int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

// Checks if a string represents a valid integer (handles signs)
int is_number_str(const char *str)
{
    int i = 0;

    if (str == NULL || *str == '\0')
        return (0); // Not a number if empty or NULL
    if (str[i] == '-' || str[i] == '+')
    {
        i++;
        if (str[i] == '\0') // Just a sign is not a number
            return (0);
    }
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0); // Not a digit
        i++;
    }
    return (1); // All checks passed
}

// A simple custom atol to convert string to long, with basic overflow check
long ft_atol(const char *str)
{
    long	result = 0;
    int		sign = 1;
    int		i = 0;

    while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (ft_isdigit(str[i]))
    {
        // Basic overflow/underflow check before multiplication
        if (sign == 1 && result > (LONG_MAX - (str[i] - '0')) / 10)
            exit_error(); // Overflow
        if (sign == -1 && result < (LONG_MIN + (str[i] - '0')) / 10) // Careful with negative logic
            exit_error(); // Underflow (this check is a bit tricky for negatives)
                         // A more robust way is to check after result * 10 + digit

        result = result * 10 + (str[i] - '0');
        i++;
    }
    result *= sign;
    if (result > INT_MAX || result < INT_MIN) // Final check against INT limits
        exit_error();
    return (result);
}

// Helper to check if stack A is sorted by rank
// REMOVED STATIC KEYWORD
int is_sorted(t_stack *stack)
{
    t_stack_node *current;

    if (!stack || stack->size <= 1)
        return (1); // Empty or single element stack is sorted
    current = stack->top;
    while (current && current->next) // Added check for current to be safe
    {
        if (current->rank > current->next->rank)
            return (0); // Not sorted
        current = current->next;
    }
    return (1); // Sorted
}