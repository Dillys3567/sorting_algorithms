#include "sort.h"
#include <stdio.h>

void swap(int *array, size_t pos1, size_t pos2);

/**
 * selection_sort - perform selection sort on array
 * @array: array to sort
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t unsorted_i = 0, ele_pos = 0, sorted_i = 0;

	if (!array || size <= 1)
		return;
	while (sorted_i < size)
	{
		unsorted_i = sorted_i;
		ele_pos = sorted_i;
		while (unsorted_i < size)
		{
			if (array[unsorted_i] < array[ele_pos])
			{
				ele_pos = unsorted_i;
				if (unsorted_i + 1 == size)
					break;
			}
			unsorted_i++;
		}
		if (array[ele_pos] < array[sorted_i])
		{
			swap(array, sorted_i, ele_pos);
			print_array(array, size);
		}
		sorted_i++;
	}
}
/**
 * swap - swap two array elements
 * @array: array
 * @pos1: position 1
 * @pos2: position 2
 */
void swap(int *array, size_t pos1, size_t pos2)
{
	int temp;

	temp = array[pos2];
	array[pos2] = array[pos1];
	array[pos1] = temp;
}
