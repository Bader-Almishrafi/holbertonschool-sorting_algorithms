#include "sort.h"
/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
int *count, *output;
size_t i;
int max = 0;
if (!array || size < 2)
return;
/* find max value */
for (i = 0; i < size; i++)
{
if (array[i] > max)
max = array[i];
}
count = malloc(sizeof(int) * (max + 1));
if (!count)
return;
for (i = 0; i <= (size_t)max; i++)
count[i] = 0;
/* count occurrences */
for (i = 0; i < size; i++)
count[array[i]]++;
/* cumulative count */
for (i = 1; i <= (size_t)max; i++)
count[i] += count[i - 1];
/* print counting array */
print_array(count, max + 1);
output = malloc(sizeof(int) * size);
if (!output)
{
free(count);
return;
}
/* build output array (stable) */
for (i = size; i > 0; i--)
{
output[count[array[i - 1]] - 1] = array[i - 1];
count[array[i - 1]]--;
}
/* copy back */
for (i = 0; i < size; i++)
array[i] = output[i];
free(count);
free(output);
}
