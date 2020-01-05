#include "monty.h"
/**
*push- Insert new element to the stack
*@stack: head of a linked list
*@line_number: line number
*/
void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int number = 0;
	(void) line_number;

	arg = strtok(NULL, "\n\t\r ");
	if (arg == NULL || check_number(arg, line_number))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	number = atoi(arg);
	if (addnode(stack, number) == NULL)
	{
		dprintf(STDOUT_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}
/**
*pall- Prints all the values on the stack, starting from the top
*@stack: head of a linked list
*@line_number: line number
*/
void pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	print_dlistint(*stack);
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
