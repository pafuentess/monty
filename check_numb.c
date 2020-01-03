#include "monty.h"
/*
*check_number- check if num is number
*@num: char  pointer
*Return: 1 if num is number or -1 if num is not a number
*/
int check_number(char *num)
{
	int i;

	i = 0;
	while (num[i])
	{
		if (num[i] < 47 || num[i] > 58)
		{
			return (-1);
		}
		i++;
	}
	return (1);
}


