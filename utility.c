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

/**
 * print_array - prints all elements in the array
 *
 * @array: array of integers
 * @size: size of the array
 *
 * Return: void
 */
void print_array(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i != size - 1)
			printf(", ");
	}
	putchar('\n');
}
