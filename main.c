#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * main - This program interprets Monty ByteCodes files
 * @ac: Number of arguments passed to a function
 * @av: Array of arguments
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	FILE *file;
	stack_t *stack = NULL;

	argv = malloc(sizeof(char *) * 50);
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free(argv);
		exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		free(argv);
		exit(EXIT_FAILURE);
	}

	_read(file, &stack);
	free(argv);
	free_list(stack);
	fclose(file);
	return (0);
}
