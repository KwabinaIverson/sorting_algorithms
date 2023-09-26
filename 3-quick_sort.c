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
 * partition - splits the array using the last
 * element as the pivot
 * @array: array to split
 * @left: leftmost index in array
 * @right: rightmost index in array
 * @size: size of array
 * Return: index of pivot after swapping
 */
int partition(int *array, size_t left, size_t right, size_t size)
{
	int pivot;
	size_t j, i;

	pivot = array[right];

	/*idx of smaller element*/
	i = left - 1;

	for (j = left; j <= right - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (j != i)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i != right)
	{
		swap(&array[i+ 1], &array[right]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * q_sort - sorts an array using the quick sort algo
 * @array: array to sort
 * @left: leftmost index
 * @right: rightmost index
 * @size: size of array
 */
void q_sort(int *array, int left, int right, size_t size)
{
	int pi;  /*pivot index*/

	if (left < right)
	{
		pi = partition(array, left, right, size);

		/*left side*/
		q_sort(array, left, pi - 1, size);

		/*right side*/
		q_sort(array, pi + 1, right, size);
	}
}

/**
 * quick_sort - sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: array of ints to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	size_t left = 0;
	size_t right = size - 1;

	if (array == NULL || size <2)
		return;

	q_sort(array, left, right, size);
}
