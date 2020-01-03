#include "monty.h"


int main(int argc, char **argv)
{
        char *buff, **token;
        int i = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

        buff = read_textfile(argv[1]);
        token = tokenizar(buff, "\n");
        while (token[i])
        {
                check(token[i]);
                i++;
        }
        return (0);
}

