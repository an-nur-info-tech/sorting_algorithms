#include "sort.h"
/**
 * _swap - swaped 2 values.
 * @array: the array for swap him values.
 * @a: First index
 * @b: Second index
 * Return: Nothing
 */
void _swap(int *array, int a, int b)
{
	int tmp;

	if (array[a] != array[b])
	{
		tmp = array[a];
		array[a] = array[b];
		array[b] = tmp;
	}
}

/**
 * shell_sort - sort the list and print the changes
 * @array: The array to sort.
 * @size: Size of the array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t h = 0,  i, j;

	if (size < 2)
		return;

	while (h <= size / 3)
		h = h * 3 + 1;

	while (h >= 1)
	{
		for (i = h; i < size; i++)
			for (j = i; j >= h && array[j] < array[j - h]; j -= h)
				_swap(array, j, j - h);
		h /= 3;
		print_array(array, size);
	}
}
