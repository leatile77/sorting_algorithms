#include <stdlib.h>
#include <stdio.h>
#include "sort.h"


void swap(int *x, int *y);
void qs_recursive(int arr[], int low, int high, size_t size);
int lomuto_partition(int a[], int low, int high, size_t size);


/**
 * quick_sort - Function that perfomrs quick sorting on array of integers.
 * @array: Array of integers to sort.
 * @size: Length of array.
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
{
return;
}
qs_recursive(array, 0, size - 1, size);
}


/**
 * qs_recursive - Function that recursively calls partition
 * until fully partitioned.
 * @arr: Array of integers to sort.
 * @low: starting index of partition.
 * @high: Ending index of partition.
 * @size: Size of full array.
 *
 * Return: void
 */

void qs_recursive(int arr[], int low, int high, size_t size)
{
int pivIndex;

if (low < high)
{
pivIndex = lomuto_partition(arr, low, high, size);
qs_recursive(arr, low, pivIndex - 1, size);
qs_recursive(arr, pivIndex + 1, high, size);
}
}


/**
 * lomuto_partition - Function that partitions array and sort elements.
 * @a: Array of integers to partition.
 * @low: starting index of partition.
 * @high: Ending index of partition.
 * @size: Size of full array.
 *
 * Return: index of current pivot after partition.
 */

int lomuto_partition(int a[], int low, int high, size_t size)
{
int piv, k, i;
piv = a[high];
k = low - 1;


for (i = low; i <= high - 1; i++)
{
if (a[i] <= piv)
{
k++;
if (k != i)
{
swap(&a[k], &a[i]);
print_array(a, size);
}
}
}

swap(&a[k + 1], &a[high]);

if (k + 1 != high)
{
print_array(a, size);
}

return (k + 1);
}


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
