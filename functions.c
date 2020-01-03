#include "monty.h"

/**
* read_textfile - eads a text file and prints it to
* the POSIX standard output.
* @filename: file to read
* @letters: numbers of letters to read
* Return: the text inside the file
*/

char *read_textfile(char *filename)
{
	int fd;
	ssize_t st;
	char *buff = malloc(1024 * sizeof(char *));

	if (filename == NULL)
		return (NULL);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	st = read(fd, buff, 1024);
	close(fd);

	if (st == -1)
		return (NULL);

	return (buff);
}

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

int check(char *buffer, stack_t **header, unsigned int line_number)
{
	instruction_t op[] = {{"push", push}, {"pint", pint}, {"pall", pall}, {NULL, NULL}};
	int i = 0, is_num = 0, len = 0;
	char **token;
	
	token = tokenizar(buffer, " ");
	len = count_ar(token);
	if (len < 2 && ((strcmp(token[0], "push") == 0)))
	{	
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

/*	printf("line number %d, len %d\n", line_number, len); */
	
	if (len >= 2)
	{
		if ((is_num = check_number(token[1])) == 1)
			number = atoi(token[1]);
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
	return (0);
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
