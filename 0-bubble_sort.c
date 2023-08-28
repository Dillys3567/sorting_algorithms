#include "sort.h"

void swap(int *array, size_t ind_1, size_t ind_2);

/**
 * bubble_sort - perform bubble sort on array
 * @array: array to sort
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	BOOL sorted = FALSE;
	size_t i, sorted_i = size - 1;

	if (!array || size <= 1)
		return;
	while (!sorted)
	{
		sorted = TRUE;
		for (i = 0; i < sorted_i; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array, i, i + 1);
				sorted = FALSE;
				print_array(array, size);
			}
		}
		sorted_i--;
	}
}
/**
 * swap - swap array elements
 * @array: array to swap elements
 * @ind_1: index 1
 * @ind_2: index 2
 */
void swap(int *array, size_t ind_1, size_t ind_2)
{
	int temp;

	temp = array[ind_1];
	array[ind_1] = array[ind_2];
	array[ind_2] = temp;
}
