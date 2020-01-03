#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

/**
* get_dnodeint_at_index -returns the nth node of
* a listint_t linked list.
* @head: pointer of head the linked list
* @index: index of nth node
* Return: head in the index position
*/
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index)
{
	unsigned int i;

	for (i = 0 ; i < index ; i++)
	{
		if (head == NULL)
			return (NULL);
		head = head->next;
	}

	return (head);
}

/**
* sum_dlistint - sum of all the data (n)
* of a listint_t linked list.
* @head: head of a linked list
* Return: sum
*/
int sum_dlistint(stack_t *head)
{
	int sum = 0;

	while (head)
	{
		sum = sum + head->n;
		head = head->next;
	}

	return (sum);

}

/**
* insert_dnodeint_at_index - insert a new node at index
* @h: head linked list
* @idx: index to insert a node
* @n: int to fill the new node
* Return: new node
*/
stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n)
{
	stack_t *new_node, *tmp1, *tmp2;
	unsigned int i;

	if (h == NULL)
		return (NULL);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;

	if (idx != 0)
	{
		tmp2 = *h;
		for (i = 0; i < idx - 1 && tmp2 != NULL; i++)
			tmp2 = tmp2->next;
		if (tmp2 == NULL)
			return (NULL);
	}
	if (idx == 0)
	{
		tmp1 = *h;
		*h = new_node;
		new_node->prev = NULL;
	}
	else
	{
		new_node->prev = tmp2;
		tmp1 = tmp2->next;
:	tmp2->next = new_node;
	}
	new_node->next = tmp1;
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
	return (new_node);
}

/**
* delete_dnodeint_at_index - deletes the node at index index
* @head: head of linked list
* @index: index to delete
* Return: 1 if it succeeded, -1 if it failed
*/
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *tmp;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		tmp = *head;
		*head = tmp->next;
		if (tmp->next != NULL)
		{
			tmp->next->prev = NULL;
		}
		free(tmp);
		return (1);
	}
	tmp = *head;
	for (i = 0; i < index; i++)
	{
		if (tmp->next == NULL)
			return (-1);
		tmp = tmp->next;
	}
	tmp->prev->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;
	free(tmp);
	return (1);
}
