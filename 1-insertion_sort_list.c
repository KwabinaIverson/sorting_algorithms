#include "sort.h"

/**
 * swap_nodes - swaps positions of node1(1st) with node2 (2nd)
 * @node1: first node. Node on the left.
 * @node2: second node. Node on the right.
 * Return: Returns head of list
 */
listint_t *swap_nodes(listint_t *node1, listint_t *node2, listint_t *head)
{
	listint_t *tmp;

	tmp = malloc(sizeof(listint_t));

	if (!tmp)
		return NULL;

	/* Copy first node to tmp */
	tmp->prev = node1->prev;
	tmp->next = node1->next;

	node1->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->prev = node2;
	node2->prev = tmp->prev;
	node2->next = node1;

	if (tmp->prev != NULL)
		tmp->prev->next = node2;

	/* Free memory allocation for tmp */
	free(tmp);

	if (node2->prev == NULL)
		return node2;  // Return the new head of the list
	return (head);
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *h, *c_node, *p_node;
	h = *list;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (h != NULL)
	{
		c_node = (*list)->next;
		p_node = *list;

		while (c_node != NULL)
		{
			int x = c_node->n;
			int y = p_node->n;  /* set up vars to check `n` of node */

	/* If `n` of c_node (x) > p_node (y)... swap nodes */
			if (y > x)
			{
				*list = swap_nodes(p_node, c_node, h);  /*Update the head pointer*/
				print_list(*list);
				c_node = (*list)->next;
				p_node = *list;
				h = *list;  /*set `h` to new head*/
			}
			else
			{
				c_node = c_node->next;
				p_node = p_node->next;
			}
		}
        	h = h->next;
	}
}
