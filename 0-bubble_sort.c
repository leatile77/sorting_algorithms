#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - Function that sorts an array of integers
 * in ascending order using bubble sorting.
 * @array: array of integers to sort.
 * @size: size of array.
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
size_t i, j;
int tmp;

if (size < 2)
{
return;
}

for (i = 0; i < size - 1; i++)
{
for (j = 0; j < size - i - 1; j++)
{
if (array[j] > array[j + 1])
{
tmp = array[j];
array[j] = array[j + 1];
array[j + 1] = tmp;
print_array(array, size);
}
}
}
}
