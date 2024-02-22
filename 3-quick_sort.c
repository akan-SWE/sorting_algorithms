#include "sort.h"
#include <stdio.h>

/**
 * quick_sort_helper - quicksort helper function
 *
 * @array: the current array
 * @size: size of the current array
 * @arrayInfo: stores the original array and size
 *
 * Return: void
 */
void quick_sort_helper(int *array, size_t size, ArrayInfo arrayInfo)
{
	size_t pivot;

	if (array == NULL || size <= 1)
		return;

	pivot = partition(array, size, arrayInfo);

	quick_sort_helper(array, pivot, arrayInfo);
	quick_sort_helper(array + pivot + 1, size - pivot - 1, arrayInfo);
}

/**
 * quick_sort - Sorts an array using the quicksort algorithm
 *
 * @array: the current array
 * @size: size current of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	ArrayInfo arrayInfo;

	arrayInfo.array = array;
	arrayInfo.size = size;

	quick_sort_helper(array, size, arrayInfo);
}

/**
 * partition - Creates partition to the array, rightly
 * splitting it in two
 *
 * @array: the current array
 * @size: size current of the array
 * @arrayInfo: stores the original array and size
 *
 * Return: void
 */
size_t partition(int *array, size_t size, ArrayInfo arrayInfo)
{
	size_t i = -1, j;
	int temp, pivot;

	pivot = array[size - 1];
	for (j = 0; j < size; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				print_array(arrayInfo.array, arrayInfo.size);
			}
		}
	}

	return (i);
}
