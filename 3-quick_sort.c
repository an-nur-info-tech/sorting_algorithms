#include "sort.h"

/**
 * _swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */

void _swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @lb: The lower bound
 * @ub: The upper bound.
 *
 * Return: The final partition index.
 */

int partition(int *array, size_t size, int lb, int ub)
{
	int *pivot, above, below;

	pivot = array + ub;
	for (above = below = lb; below < ub; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				_swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		_swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * _sort_recursive - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @lb: The lower bound.
 * @ub: The upper bound.
 *
 * Description: Uses the Lomuto partition scheme.
 */

void _sort_recursive(int *array, size_t size, int lb, int ub)
{
	int pivot_index;

	if (lb < ub)
	{
		pivot_index = partition(array, size, lb, ub);

		_sort_recursive(array, size,  lb, pivot_index - 1);
		_sort_recursive(array, size, pivot_index + 1, ub);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	_sort_recursive(array, size, 0, size - 1);
}
