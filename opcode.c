#include "monty.h"


void push(stack_t **stack, unsigned int line_number)
{	
	stack_t *new_node;
	(void) line_number;
/*	printf("paula\n");*/
	new_node = malloc(sizeof(stack_t));
	
	if (new_node == NULL)
		 exit(EXIT_FAILURE);
/*	printf("fuentes\n");*/
	new_node->prev = NULL;
	new_node->next = *stack;
	*stack = new_node;
	new_node->n = number;

	if (new_node->next != NULL)
		(new_node->next)->prev = new_node;
/*	printf("paulita\n");*/
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void) line_number;
	
/*	printf("entre");*/
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
