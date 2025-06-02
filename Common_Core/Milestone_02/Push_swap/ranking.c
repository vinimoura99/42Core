#include "push_swap.h"

// A simple bubble sort for an array of integers (for ranking)
// We use this on a temporary array of values, not directly on the stack nodes.
static void bubble_sort_array(int *arr, int size)
{
    int i;
    int j;
    int temp;
    int swapped;

    if (!arr || size < 2)
        return;
    i = 0;
    while (i < size - 1)
    {
        swapped = 0;
        j = 0;
        while (j < size - 1 - i)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
            j++;
        }
        if (swapped == 0) // If no two elements were swapped by inner loop, then break
            break;
        i++;
    }
}

// Assigns ranks to the nodes in the stack
// Rank 0 for the smallest value, up to stack->size - 1 for the largest.
void assign_ranks(t_stack *stack)
{
    int				*values_array;
    int				i;
    t_stack_node	*current_node;

    if (!stack || !stack->top || stack->size == 0)
        return;

    // 1. Create a temporary array and copy all values from the stack
    values_array = (int *)malloc(sizeof(int) * stack->size);
    if (!values_array)
        exit_error(); // Or handle memory allocation error

    current_node = stack->top;
    i = 0;
    while (current_node)
    {
        values_array[i++] = current_node->value;
        current_node = current_node->next;
    }

    // 2. Sort the temporary array
    bubble_sort_array(values_array, stack->size);

    // 3. Assign ranks back to stack nodes
    // For each node in the original stack, find its value in the sorted array.
    // The index in the sorted array is its rank.
    current_node = stack->top;
    while (current_node)
    {
        i = 0;
        while (i < stack->size)
        {
            if (current_node->value == values_array[i])
            {
                current_node->rank = i;
                break; // Found rank, move to next node
            }
            i++;
        }
        current_node = current_node->next;
    }

    // 4. Free the temporary array
    free(values_array);
}