#include "sort.h"

/**
 * cocktail_sort_list - sorts an array using the cocktail shaker sort algorithm
 *
 * @list: A reference to the pointer to the first node
 *
 * Return: void
 **/
void cocktail_sort_list(listint_t **list)
{
	listint_t *iter1 = *list, *iter2, *last = NULL;
	bool not_sorted, move;

	do {
		move = true, not_sorted = false;
		iter1 = *list;
		/* bubble current highest number up */
		while (iter1->next != last)
		{
			move = true;
			if (iter1->n > iter1->next->n)
			{
				swap(&iter1, &iter1->next);
				/* update list*/
				while ((*list)->prev)
					*list = (*list)->prev;
				not_sorted = true, move = false;
				print_list(*list);
			}
			if (move)
				iter1 = iter1->next;
		}
		last = iter1, iter2 = last;
		/* bubble current smallest down */
		while (iter2->prev != *list)
		{
			move = true;
			if (iter2->n < iter2->prev->n)
			{
				swap(&iter2->prev, &iter2);
				/* update list */
				while ((*list)->prev)
					*list = (*list)->prev;
				not_sorted = true, move = false;
				print_list(*list);
			}
			if (move)
				iter2 = iter2->prev;
		}
	} while (not_sorted);
}

/**
 * swap - Swap two nodes
 *
 * @first: firt node
 * @second: second node
 *
 * Return: void
 */
void swap(listint_t **first, listint_t **second)
{
	listint_t *temp_next = (*first)->next;
	listint_t *temp_prev = (*first)->prev;

	if (*first == NULL || *second == NULL)
		return;

	if ((*first)->prev)
		(*first)->prev->next = *second;
	if ((*second)->next)
		(*second)->next->prev = *first;

	(*first)->next = temp_next->next; /* 2 -> NULL */
	(*first)->prev = temp_next;		  /* q <- 2 */

	temp_next->next = *first; /* 1 -> 2 */
	temp_next->prev = temp_prev;
}
