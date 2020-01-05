#include "monty.h"

/**
* addnode- add node at head of list
* @head: pointer to list
* @n: data to add
* Return: pointer to new node
*/

stack_t *addnode(stack_t **head, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		return (NULL);
	(*new_node).n = n;
	(*new_node).prev = NULL;
	(*new_node).next = *head;
	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
	return (new_node);
}
