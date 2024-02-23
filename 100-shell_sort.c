#include "sort.h"

/**
 * shell_sort - sorts an array using shell sort algorithm
 * and the knuth sequence
 *
 * @array: the array
 * @size: size of the array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t gap;
	/* can't swap when array is empty or size is less than 2*/
	if (array == NULL || size < 2)
		return;

	/* initial gap */
	gap = 1;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	for (; gap > 0; gap /= 3)
	{
		size_t i;

		for (i = gap; i < size; i++)
		{
			int temp = array[i];
			size_t j;

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
	}
}
