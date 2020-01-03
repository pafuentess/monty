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

void check(char *buffer)
{
	instruction_t op[] = {{"push", push}, {NULL, NULL}};
	int i = 0, is_num = 0, len = 0;
	char **token;
	stack_t **stack;

	len = strlen(buffer);
	if (len < 1)
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
                exit(EXIT_FAILURE);
	}
	stack = NULL;
	if ((is_num = check_num(token[1])) == 1)
	{
		token = tokenizar(buffer, " ");
		number = atoi(token[1]);
		while (op[i].opcode != NULL)
		{
			if (strcmp(token[0], op[i].opcode) == 0)
				(op[i].f)(stack, line_number);
			i++;
		}
		else
		{
                	printf(stderr, "L%d: usage: push integer", line_number);
                	exit(EXIT_FAILURE);
		}
	}
        	
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
