#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	int temp, i, j;

	if (array == NULL || size < 2)
		return;

	/* Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < (int)size; i++)
		{
			temp = array[i];
			j = i;

			/* Swap the integers */
			while (j >= (int)gap && array[j - gap] > temp)
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
