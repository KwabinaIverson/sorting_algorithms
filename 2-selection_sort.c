#include "sort.h"

/**
 * selection_sort - sorts an array of integers in
 * ascending order using the Selection sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{

	int i, j, tmp, idx, s_num, swapped, arr_size;

	if (array == NULL)
		return;

	arr_size = size;
	i = 0, j = 0, idx = 0, tmp = 0;

	while (size--)
	{
		s_num = array[j];
		swapped = 1;

		for (i = j; i < arr_size; i++)
		{
			/*get smallest num & idx */
			if (array[i] < s_num)
			{
				s_num = array[i];
				idx = i;
				swapped = 0;
			}
        	}
 
		if (swapped == 0)
		{
			tmp = array[j];
			array[j] = array[idx];
			array[idx] = tmp;
			print_array(array, arr_size);
		}
		j++;
	}
}
