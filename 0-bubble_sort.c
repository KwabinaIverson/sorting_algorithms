#include "sort.h"


/**
 * swap - swaps a pair of numbers. Lesser num first
 * @num1: first number
 * @num2: second number
 */
void swap(int *num1, int *num2)
{
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped;  /* 0 = True, 1 = False */

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 1;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = 0;
				print_array(array, size);
			}
		}
		/* if no two elements were swapped - break loop */
		if (swapped == 1)
			break;
	}
}
