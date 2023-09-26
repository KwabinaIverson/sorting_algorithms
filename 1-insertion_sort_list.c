#include "sort.h"

/**
 * insert_sort_list - insert node in a sorted doubly linked list
 * @list: Address to the node
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert_point, *next_node;

	/* Check for empty list */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		insert_point = current->prev;
		next_node = current->next;

		/* Insert node previous node is not NULL and n is greater */
		while (insert_point != NULL && insert_point->n > current->n)
			insert_point = insert_point->prev;

		if (insert_point == NULL)
		{
			/* Insert node at the beginning */
			current->prev->next = next_node;
			if (next_node != NULL)
				next_node->prev = current->prev;
			current->prev = NULL;
			current->next = *list;
			(*list)->prev = current;
			*list = current;
		}
		else
		{
			/* Insert node at the middle or end */
			current->prev->next = next_node;
			if (next_node != NULL)
				next_node->prev = current->prev;
			current->prev = insert_point;
			current->next = insert_point->next;
			if (insert_point->next != NULL)
				insert_point->next->prev = current;
			insert_point->next = current;
		}
		print_list(*list);
		current = next_node;
	}
}
