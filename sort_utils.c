#include "sort.h"

/**
 * swap - swaps two integers in the array
 *
 * @array: array of integers
 * @index: the index
 *
 * Return: void
 */
void swap(int *array, size_t index)
{
	int temp = array[index];

	array[index] = array[index + 1];
	array[index + 1] = temp;
}
