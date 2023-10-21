#include "sort.h"

/**
 * swap_int - swap two integers
 * @a: first int to swap
 * @b: second int to swap
 *
 * Description: swap a with b
 */
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - sort an algorithm
 * @array: array to sort
 * @size: size of the array
 *
 * Description: sort an  array and print
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped;

	if (array == NULL || size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_int(array + j, array + j + 1);
				swapped = 1;
				print_array(array, size);
			}
		}

		if (swapped == 0)
		{
			break;
		}

	}

}

