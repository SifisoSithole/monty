#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * main - This program interprets Monty ByteCodes files
 * @ac: Number of arguments passed to a function 
 * @argv: Array of arguments
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	FILE *file;
	stack_t **stack = NULL;
	
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	_read(file, stack);
	fclose(file);
	return (0);
}
