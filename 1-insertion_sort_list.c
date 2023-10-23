#include "sort.h"

/**
 * swap_nodes - Swap two nodes of a doubly-linked list.
 * @head: A pointer to the head of the list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void swap_nodes(listint_t **head, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*head = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - insertion sort algorithm that sorts
 *                       a doubly linked list of an integers.
 * @list: A pointer to the head of a doubly-linked list of an integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *loop, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (loop = (*list)->next; loop != NULL; loop = temp)
	{
		temp = loop->next;
		insert = loop->prev;
		while (insert != NULL && loop->n < insert->n)
		{
			swap_nodes(list, &insert, loop);
			print_list((const listint_t *)*list);
		}
	}
}
