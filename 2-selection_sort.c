#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - Function that performs selection sort on array of integers.
 * @array: array of integers to sort.
 * @size: size of array.
 *
 * Return: void
 */


void selection_sort(int *array, size_t size)
{
size_t i, j, minIdx;
int tmp, swapped;

if (size < 2)
{
return;
}

for (i = 0; i < size; i++)
{
minIdx = i;
swapped = 0;

for (j = i + 1; j < size; j++)
{

if (array[j] < array[minIdx])
{
minIdx = j;
swapped = 1;
}
}

if (swapped)
{
tmp = array[i];
array[i] = array[minIdx];
array[minIdx] = tmp;
print_array(array, size);
}
}

}
