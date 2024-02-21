#include "sort.h"

/**
 * insertion_sort_list - sorts a linked list using the insertion sort
 * algorithm
 *
 * @list: A reference to the pointer to the first node in the list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *current, *prev, *next;

	/* list is empty */
	if (*list == NULL)
		return;

	temp = (*list)->next;
	while (temp)
	{
		/* iterate through the list */
		current = temp;
		while (current && current->prev && current->prev->n > current->n)
		{
			/* swap if previous node is greate than current */
			prev = current->prev->prev;
			next = current->next;

			if (prev)
				prev->next = current;
			if (next)
				next->prev = current->prev;

			current->next = current->prev;
			current->prev->prev = current;

			current->prev->next = next;
			current->prev = prev;

			/* update temp of the list */
			while ((*list)->prev)
				*list = (*list)->prev;

			print_list(*list);
		}
		temp = temp->next;
	}
}
