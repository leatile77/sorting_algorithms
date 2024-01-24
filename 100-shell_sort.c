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
 * shell_sort - Function that performs shell sort on an array.
 * @array: Array to be sorted.
 * @size: Length of array.
 *
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
int tmp;
size_t i, j, k;
k = 1;

if (array == NULL || size < 2)
{
return;
}
 
while (k < (size / 3))
{
k = k * 3 + 1;
}

while (k > 0)
{
for (i = k; i < size; i++)
{
tmp = array[i];
for (j = i; j >= k && array[j - k] > tmp; j = j - k)
{
swap(&array[j], &array[j - k]);
}
}
print_array(array, size);

k /= 3;
}
}
