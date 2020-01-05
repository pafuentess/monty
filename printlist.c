#include "monty.h"

/**
 *print_dlistint - prints all the elements of a dlistint_t list.
 *@h: header of the doubly linked list
 *Return: the number of nodes
 */

size_t print_dlistint(const stack_t *h)
{
	unsigned int i = 0;

	if (h == NULL)
		return (i);
	while (h != NULL)
	{
		printf("%i\n", (*h).n);
		h = (*h).next;
		i++;
	}
	return (i);
}
