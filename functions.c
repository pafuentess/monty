#include "monty.h"
#include <ctype.h>

/**
*check- function to check words
*@buffer: buffer
*@header: double pointer stack_t
*@line_number: line number
*/
void check(char *buffer, stack_t **header, unsigned int line_number)
{
	instruction_t op[] = {{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop}, {"sub", sub},
		{"div", div_fun}, {"mul", mult}, {"mod", mod_fun}, {NULL, NULL}};
	int i = 0;

	while (op[i].opcode != NULL)
	{
		if (strcmp(buffer, op[i].opcode) == 0)
		{
			(op[i].f)(header, line_number);
			return;
		}
		i++;
	}
	free_stack(header);
	fprintf(stderr, "L%d: unknown instructions %s\n", line_number, buffer);
	exit(EXIT_FAILURE);
}

/**
*check_number- check if num is number
*@num: char  pointer
*@line_number: line number
*Return: 1 if num is number or -1 if num is not a number
*/
int check_number(char *num, unsigned int line_number)
{
	int i = 0;
	(void) line_number;

	if (num[i] == '-')
		i++;

	while (num[i])
	{
		if (isdigit(num[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
/**
*count_ar- count
*@token: double pointer
*Return: integer
*/
int count_ar(char **token)
{
	int i = 0;

	while (token[i])
		i++;
	return (i);
}
