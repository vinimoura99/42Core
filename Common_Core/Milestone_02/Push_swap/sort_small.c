#include "push_swap.h"

// Sorts a stack of 2 elements if needed
static void sort_two(t_stack *stack_a)
{
    if (!stack_a || stack_a->size != 2)
        return;
    if (stack_a->top->rank > stack_a->top->next->rank)
        sa(stack_a, 1);
}

// Sorts a stack of 3 elements
static void sort_three(t_stack *stack_a)
{
    int r0, r1, r2;

    if (!stack_a || stack_a->size != 3)
        return;
    r0 = stack_a->top->rank;
    r1 = stack_a->top->next->rank;
    r2 = stack_a->top->next->next->rank;

    if (r0 < r1 && r1 < r2)
        return;
    else if (r0 < r2 && r2 < r1) // (0,2,1)
    {
        rra(stack_a, 1);
        sa(stack_a, 1);
    }
    else if (r1 < r0 && r0 < r2 && r1 < r2) // (1,0,2)
        sa(stack_a, 1);
    else if (r2 < r1 && r1 > r0 && r0 < r1) // (1,2,0) r0=1, r1=2, r2=0
    {
        rra(stack_a, 1);
    }
    else if (r1 < r2 && r2 < r0 && r0 > r1) // (2,0,1) r0=2, r1=0, r2=1
    {
        ra(stack_a, 1);
    }
    else // (2,1,0)
    {
        sa(stack_a, 1);
        rra(stack_a, 1);
    }
}

// Helper function to find the node with a specific rank and bring it to the top of stack_a
// Returns the number of rotations performed (positive for ra, negative for rra)
// This is a common utility you might want to refine or move to a utils file later.
static void bring_to_top_a(t_stack *stack_a, int target_rank)
{
    t_stack_node	*current;
    int				pos;
    int				moves;
    int				size;

    if (!stack_a || !stack_a->top)
        return;
    size = stack_a->size;
    if (size <= 1)
        return;

    pos = 0;
    current = stack_a->top;
    while (current)
    {
        if (current->rank == target_rank)
            break;
        pos++;
        current = current->next;
    }

    if (!current) // Rank not found (should not happen if logic is correct)
        return;

    if (pos == 0) // Already at top
        return;

    if (pos <= size / 2) // Cheaper to use ra
    {
        moves = pos;
        while (moves-- > 0)
            ra(stack_a, 1);
    }
    else // Cheaper to use rra
    {
        moves = size - pos;
        while (moves-- > 0)
            rra(stack_a, 1);
    }
}

// Sorts a stack of 4 elements
static void sort_four(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a || stack_a->size != 4)
        return;

    // Bring element with rank 0 to the top of A
    bring_to_top_a(stack_a, 0);
    // Push it to B
    pb(stack_a, stack_b);

    // Now stack_a has 3 elements (ranks 1, 2, 3 in some order)
    // Their effective ranks for sort_three will be 0, 1, 2 relative to each other.
    // sort_three works on the absolute ranks, which is fine.
    sort_three(stack_a);

    // Push back from B to A
    pa(stack_a, stack_b);
}

// Sorts a stack of 5 elements
static void sort_five(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a || stack_a->size != 5)
        return;

    // Bring element with rank 0 to top and push to B
    bring_to_top_a(stack_a, 0);
    pb(stack_a, stack_b);

    // Bring element with rank 1 to top and push to B
    bring_to_top_a(stack_a, 1);
    pb(stack_a, stack_b);

    // Now stack_a has 3 elements (ranks 2, 3, 4 in some order)
    // sort_three will sort them based on their absolute ranks.
    sort_three(stack_a);

    // Push back from B to A (rank 1 then rank 0)
    pa(stack_a, stack_b); // Pushes rank 1 back
    pa(stack_a, stack_b); // Pushes rank 0 back
}


// Main dispatcher for small sorts
// Returns 1 if it handled the sort, 0 otherwise
// Now takes stack_b as it's needed for N=4 and N=5
int sort_small_stack(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a || stack_a->size <= 1)
        return (1); // Already sorted or empty

    if (is_sorted(stack_a)) // Check if already sorted before proceeding
        return (1);

    if (stack_a->size == 2)
    {
        sort_two(stack_a);
        return (1);
    }
    else if (stack_a->size == 3)
    {
        sort_three(stack_a);
        return (1);
    }
    else if (stack_a->size == 4)
    {
        sort_four(stack_a, stack_b);
        return (1);
    }
    else if (stack_a->size == 5)
    {
        sort_five(stack_a, stack_b);
        return (1);
    }
    return (0); // Not handled by this function (e.g. size > 5)
}