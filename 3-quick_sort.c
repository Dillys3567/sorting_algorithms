#include "sort.h"

void swap(int *array, size_t pos1, size_t pos2);
size_t get_pivot(int *array, size_t left, size_t right);
void sort(int *array, size_t size, size_t left, size_t right);
size_t get_partition(int *array, size_t size, size_t l, size_t r, int pvt);

/**
 * quick_sort - perform quick sort
 * @array: array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;
	sort(array, size, 0, size - 1);
}
/**
 * sort - helper for quick sort
 * @array: array
 * @size: size of array
 * @left: left bound
 * @right: right bound
 */
void sort(int *array, size_t size, size_t left, size_t right)
{
	size_t part_s = 0;
	int pvt = array[get_pivot(array, left, right)];

	if ((long int)right - (long int)left <= 0)
		return;
	part_s = get_partition(array, size, left, right, pvt);
	sort(array, size, left, part_s - 1);
	sort(array, size, part_s + 1, right);
}
/**
 * get_partition - recusrive sorting
 * @array: array
 * @size: size of array
 * @l: start index
 * @r: end index
 * @pvt: value of pivot
 * Return: partition midpoint
 */
size_t get_partition(int *array, size_t size, size_t l, size_t r, int pvt)
{
	size_t end;

	end = r;
	l = l - 1;
	for (r = l + 1; r < end; r++)
	{
		if (array[r] < pvt)
		{
			l++;
			if (l != r)
			{
				swap(array, l, r);
				print_array(array, size);
			}
		}
	}
	if (l + 1 != end && array[l + 1] > array[end])
	{
		swap(array, l + 1, end);
		print_array(array, size);
	}
	return (l + 1);
}
/**
 * get_pivot - get pivot
 * @array: arr
 * @left: left bound
 * @right: right bound
 * Return: index of pivot point
 */
size_t get_pivot(int *array, size_t left, size_t right)
{
	(void)array;
	(void)left;
	return (right);
}
/**
 * swap - swap 2 elements
 * @array: array
 * @pos1: position 1
 * @pos2: position 2
 */
void swap(int *array, size_t pos1, size_t pos2)
{
	int t;

	t = array[pos2];
	array[pos2] = array[pos1];
	array[pos1] = t;
}
