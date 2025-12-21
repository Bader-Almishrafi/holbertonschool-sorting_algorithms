#include "sort.h"

/**
 * shell_sort - Sorts an array using Shell sort (Knuth sequence)
 * @array: Array to sort
 * @size: Size of array
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

		/* 👇 الطباعة هنا فقط */
		print_array(array, size);

		gap = (gap - 1) / 3;
	}
}

