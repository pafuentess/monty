#include "monty.h"


void push(stack_t **stack, unsigned int line_number)
{	
	stack_t *new_node;
	(void) line_number;

	new_node = malloc(sizeof(stack_t));
	
	if (new_node == NULL)
		 exit(EXIT_FAILURE);
	new_node->prev = NULL;
	new_node->next = *stack;
	*stack = new_node;
	new_node->n = global.number;

	if (new_node->next != NULL)
		(new_node->next)->prev = new_node;
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void) line_number;
	
	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp2;

	tmp2 = *stack;
	if (tmp2 != NULL)
	{
		printf("%d\n", tmp2->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);

	}
}
