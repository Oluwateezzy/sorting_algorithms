#include "sort.h"
/**
 * swap - swap
 * @a: value
 * @b: value
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - sorts an array of integers
 * @array: list
 * @size: lenght of array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	if (array == NULL || size <= 1)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min_index = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		if (min_index != i)
		{
			swap(&array[i], &array[min_index]);
			print_array(array, size);
		}
	}
}
