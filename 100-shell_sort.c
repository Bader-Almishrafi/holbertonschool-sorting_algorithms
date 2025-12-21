#include "sort.h"

/**
 * shell_sort - Sorts an array of integers using Shell sort (Knuth sequence)
 * @array: Array of integers
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (!array || size < 2)
		return;

	/* Generate Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/* Perform shell sort */
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}

		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}

