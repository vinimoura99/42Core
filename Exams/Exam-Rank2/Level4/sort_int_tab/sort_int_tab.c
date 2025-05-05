/* Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent. */

void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i;
    int temp;
    int sorted;

    if (size < 2)
        return;

    sorted = 0;
    while (!sorted)
    {
        sorted = 1;
        i = 0;
        while (i < size - 1)
        {
            if (tab[i] > tab[i + 1])
            {
                temp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = temp;
                sorted = 0;
            }
            i++;
        }
    }
}
