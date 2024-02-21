#include "sort.h"

/**
 * selection_sort - sorts an array using selection sort algorithm
 *
 * @array: the array
 * @size: size of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, least;
	bool found_min_num = false;

	if (size < 2)
		return;

	for (i = 0; array && i < size - 1; i++)
	{
		int temp = array[i];

		for (j = i, least = i; j < size - 1; j++)
		{
			if (array[j + 1] < array[least])
			{
				least = j + 1; /* current smallest element */
				found_min_num = true;
			}

		}
		array[i] = array[least];
		array[least] = temp;

		if (found_min_num)
			print_array(array, size);
		found_min_num = false;
	}
}
