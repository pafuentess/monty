#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

/**
* print_dlistint - print linked list's elements
* @h: head linked list
* Return: number of nodes of linked list
*/
size_t print_dlistint(const dlistint_t *h)
{
	int i;
	const dlistint_t *tmp;

	tmp = h;
	i = 0;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

/**
* dlistint_len - return number of elements
* of linked lists
* @h: head linked list
* Return: len of linked list
*/

size_t dlistint_len(const dlistint_t *h)
{
	int i;
	const dlistint_t *tmp;

	tmp = h;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

/**
* add_dnodeint - add node in the beggin
* @head: head of linked list
* @n: int to fill the node
* Return: the new node
*/
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->prev = NULL;
	new_node->next = *head;
	*head = new_node;
	new_node->n = n;

	if (new_node->next != NULL)
		(new_node->next)->prev = new_node;

	return (new_node);
}

/**
* add_dnodeint_end - add a node at the end of list
* @head: head of linked list
* @n: number to fill the node
* Return: the new node
*/
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *st;

	st = *head;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (*head != NULL)
	{
		while (st->next != NULL)
		{
			st = st->next;
		}
		st->next = new_node;
		new_node->prev = st;
	}
	else
		*head = new_node;

return (new_node);
}

/**
* free_dlistint - free linked list
* @head: head of linked list
*/
void free_dlistint(dlistint_t *head)
{
	dlistint_t *st;

	while (head)
	{
		st = head->next;
		free(head);
		head = st;
	}
}
