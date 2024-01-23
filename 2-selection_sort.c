#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Function that swaps two integers.
 * @x: Pointer to the first integer to swap.
 * @y: Pointer to the second integer to swap.
 *
 * Return: void
 */

void swap(int *x, int *y)
{
int tmp;
tmp = *x;
*x = *y;
*y = tmp;
}


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
int swapped;

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
swap(&array[i], &array[minIdx]);
print_array(array, size);
}
}

}
