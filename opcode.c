#include "monty.h"
/**
*push- Insert new element to the stack
*@stack: head of a linked list
*@line_number: line number
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *arg;
	int number = 0;
	(void) line_number;

	if (stack == NULL)
		exit(1);

	arg = strtok(NULL, "\n\t\r ");
	if (arg == NULL || check_number(arg, line_number))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	number = atoi(arg);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->prev = NULL;
	new_node->next = *stack;
	*stack = new_node;
	new_node->n = number;

	if (new_node->next != NULL)
		(new_node->next)->prev = new_node;
}
/**
*pall- Prints all the values on the stack, starting from the top
*@stack: head of a linked list
*@line_number: line number
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void) line_number;

	tmp = *stack;
	while (tmp)
	{
		fprintf(stdout, "%i\n", tmp->n);
		tmp = tmp->next;
		if (tmp == *stack)
			return;
	}
}
/**
*pint- Print the value at the top of the stack
*@stack: head of a linked list
*@line_number: line number
*/
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp2;

	if (stack == NULL)
		exit(1);

	tmp2 = *stack;
	if (tmp2 != NULL)
	{
		fprintf(stdout, "%d\n", tmp2->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);

	}
}

