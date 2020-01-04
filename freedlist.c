#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

/**
* free_dlistint - free linked list
* @head: head of linked list
*/

void free_dlistint(stack_t *head)
{
	stack_t *st;

	while (head)
	{
		st = head->next;
		free(head);
		head = st;
	}
}
