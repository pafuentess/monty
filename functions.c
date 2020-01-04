#include "monty.h"

char **tokenizar(char *buff, char *special)
{
	char *check, **token = malloc(1024 * sizeof(char *));
	int i;

	if (token == NULL)
		exit(98);
	check = strtok(buff, special);
	for (i = 0; i < 1024 && check != NULL; i++)
	{
		token[i] = check;
		check = strtok(NULL, special);
	}
	token[i] = NULL;
	return (token);
}

void check(char *buffer, stack_t **header, unsigned int line_number)
{
	instruction_t op[] = {{"push", push}, {"pint", pint}, {"pall", pall},{"pop", pop}, {"swap", swap}, {NULL, NULL}};
	int i = 0, is_num = 0, len = 0, compare_token = 0;
	char **token;

	token = tokenizar(buffer, "\t ");
	if (token[0] == NULL)
		return;
	compare_token = strcmp(token[0], "push");
	len = count_ar(token);
	if (compare_token != 0 && len >= 2)
	{
		fprintf(stderr, "L%d: unknow instructions %s\n", line_number, token[0]);
		exit(EXIT_FAILURE);
	}
	if (len < 2 && ((strcmp(token[0], "push") == 0)))
	{	
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (len >= 2)
	{
		if ((is_num = check_number(token[1])) == 1)
			global.number = atoi(token[1]);
	}
	while (op[i].opcode != NULL)
	{
		if (strcmp(token[0], op[i].opcode) == 0)
		{
			(op[i].f)(header, line_number);
			break;
		}
		i++;
	}
	if (op[i].opcode == NULL)
	{	
		fprintf(stderr, "L%d: unknown instructions %s\n", line_number, token[0]);
		exit(EXIT_FAILURE);
	}
	return;
}

/*
*check_number- check if num is number
*@num: char  pointer
*Return: 1 if num is number or -1 if num is not a number
*/

int check_number(char *num)
{
        int i = 0;

        while (num[i])
        {
                if (num[i] < 47 || num[i] > 58)
			return (-1);
                i++;
        }
        return (1);
}

int count_ar(char **token)
{
	int i = 0;
	
	while (token[i])
		i++;
	return (i);
}

void get_op(char *ops, stack_t *stack, unsigned int line_number)
{	
	instruction_t op[] = {{"push", push}, {"pint", pint}, {"pall", pall}, {NULL, NULL}};

	size_t i;
	printf("entro al check");
	for (i = 0; op[i].opcode != NULL; i++)
	{
		if (strcmp(op[i].opcode, ops) == 0)
		{
			op[i].f(&stack, line_number);
			return;
		}
	}

}
