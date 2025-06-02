#include "push_swap.h"

// Helper function to get the maximum rank in a stack
// (Not strictly needed if ranks are 0 to N-1, then max_rank is stack->size - 1)
// But good if ranks could be arbitrary for some reason.
// For push_swap, max_rank is always stack_a.size - 1 after assign_ranks.
/*
static int get_max_rank(t_stack *stack)
{
    t_stack_node	*current;
    int				max_rank;

    if (!stack || !stack->top)
        return (0); // Or -1 to indicate error/empty
    max_rank = stack->top->rank;
    current = stack->top->next;
    while (current)
    {
        if (current->rank > max_rank)
            max_rank = current->rank;
        current = current->next;
    }
    return (max_rank);
}
*/

// Helper function to determine the number of bits in the maximum rank
static int get_max_bits(t_stack *stack_a)
{
    int	max_rank;
    int max_bits;

    if (!stack_a || stack_a->size == 0)
        return (0);

    // In push_swap, after ranking, the ranks are 0 to (size - 1).
    // So, the maximum rank is stack_a->size - 1.
    max_rank = stack_a->size - 1;
    max_bits = 0;
    if (max_rank == 0) // For a single element or if all elements were identical (not possible with error checks)
        return (1); // Need at least 1 bit to represent 0 if we iterate once. Or 0 if no iterations needed.
                    // Let's assume we always iterate at least once if there are elements.

    while ((max_rank >> max_bits) != 0)
    {
        max_bits++;
    }
    // If max_rank was 0, loop doesn't run, max_bits is 0.
    // If size is 1, max_rank is 0. If we want to process bit 0, max_bits should be 1.
    // Let's adjust: if max_rank is 0 (e.g. size 1), max_bits should be 1 to process the 0th bit.
    if (max_bits == 0 && max_rank == 0 && stack_a->size > 0) // e.g. stack_a.size = 1, max_rank = 0
        return 1;
    return (max_bits);
}

// Radix sort algorithm
void sort_radix(t_stack *stack_a, t_stack *stack_b)
{
    int	i; // Current bit position (from LSB to MSB)
    int	j; // Counter for elements in stack_a for current bit pass
    int	num_elements_in_a;
    int	max_bits;
    int	rank_value;

    if (!stack_a || is_sorted(stack_a))
        return;

    max_bits = get_max_bits(stack_a);

    i = 0;
    while (i < max_bits) // Iterate through each bit position
    {
        num_elements_in_a = stack_a->size;
        j = 0;
        while (j < num_elements_in_a) // Process all elements currently in stack_a
        {
            rank_value = stack_a->top->rank;
            // Check the i-th bit of the rank_value
            if (((rank_value >> i) & 1) == 0) // If the i-th bit is 0
            {
                pb(stack_a, stack_b); // Push to stack B
            }
            else // If the i-th bit is 1
            {
                ra(stack_a, 1); // Rotate stack A
            }
            j++;
        }
        // After processing all elements in A for the current bit,
        // push everything from B back to A.
        while (stack_b->size > 0)
        {
            pa(stack_a, stack_b);
        }
        i++; // Move to the next bit
    }
}