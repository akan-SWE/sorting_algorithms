#include "sort.h"

/**
 * bubble_sort - sorts an array using the bubble sort algorithm
 *
 * @array: array of integers
 * @size: size of the array
 *
 * Return: void
 **/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool all_sorted = true;

	/* pick a particular integer (the current highest integer)*/
	for (i = 0; i < size; i++)
	{
		/* bubble it up to it correct position in the array */
		for (j = 0; j < (size - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array, j);
				all_sorted = false;
				print_array(array, size);
			}
		}
		if (all_sorted)
			break;
	}
}
