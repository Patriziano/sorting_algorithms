#include "sort.h"

/**
 * swap_list - The function interchanges two successive nodes
 * @pred: The node before the key
 * @key: The node to be inserted at its right position
 * Return: Nothing
 */

void swap_list(listint_t **pred, listint_t **key)
{
	listint_t *tmp;
	listint_t *newtmp;

	tmp = (*key)->next;
	newtmp = (*pred)->prev;

	if (tmp != NULL)
		tmp->prev = (*pred);
	if (newtmp != NULL)
		newtmp->next = (*key);
	(*key)->next = (*pred);
	(*pred)->next = tmp;
	(*key)->prev = newtmp;
	(*pred)->prev = (*key);
}

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 *                       in ascending order using the Insertion sort algorithm
 * @list: The pointer to the head of the list
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *key, *pred;

	if ((*list) == NULL || (*list)->next == NULL || list == NULL
			|| (*list)->prev != NULL)
		return;

	current = (*list);
	current = current->next;

	while (current != NULL)
	{
		key = current;
		pred = current->prev;
		while (pred != NULL && ((pred->n) > (key->n)))
		{
			swap_list(&pred, &key);
			pred = key->prev;
			if (pred == NULL)
				(*list) = key;
			 print_list(*list);
		}
		current = current->next;
	}
}
