#include "sort.h"
/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @node1: First node to swap
 * @node2: Second node to swap
 * Return: void
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
	if (node2->prev == NULL)
		*list = node2;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * @list: Pointer to the head of the list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		sorted = current->prev;
		while (sorted != NULL && sorted->n > current->n)
		{
			swap_nodes(list, sorted, current);
			sorted = current->prev;
			print_list(*list);
		}
		current = current->next;
	}
}
