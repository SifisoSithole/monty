#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "monty.h"

/**
 * get_tokens - This function tokenizes string
 * @str: String tokenize
 *
 * Return: 2D array
 */
void get_tokens(char *str)
{
	char *token = NULL;
	int i = 0;

	token = strtok(str, "  \0");
	while (!token)
	{
		argv[i] = token;
		i++;
		token = strtok(NULL, " \0");
	}
}

/**
 * get_func - This function selects the correct function for each opcode
 * @opcode: opcode to execute
 *
 * Return: The appropriate function
 */
void (*get_func(char *str))(stack_t **stack, unsigned int line_number)
{
	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int i;

	for (i = 0; functions[i].opcode != NULL; i++)
	{
		if (strcmp(functions[i].opcode, str) == 0)
			return (functions[i].f);
	}
	return (NULL);
}

/**
 * _read - This function reads from a file pointer
 * @f: File descriptor for the file
 */
void _read(FILE *file, stack_t **stack)
{
	char *line = NULL;
	unsigned int i = 0;
	size_t n = 0;
	void (*f)(stack_t **stack, unsigned int line_number);

	while (_getline(&line, &n, file) != -1)
	{
		get_tokens(line);
		f = get_func(argv[0]);
		if (!f)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", i, argv[0]);
			exit(EXIT_FAILURE);
		}
		f(stack, i);
		i++;
	}
	free(line);
}
