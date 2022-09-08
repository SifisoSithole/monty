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
	argv[0] = strtok(str, "\n ");
	if (argv[0] && (strcmp(argv[0], "push") == 0))
		argv[1] = strtok(NULL, "\n ");
}

/**
 * get_func - This function selects the correct function for each opcode
 * @str: ..
 *
 * Return: The appropriate function
 */
int (*get_func(char *str))(stack_t **stack, unsigned int line_number)
{
	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
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
 * @file: File descriptor for the file
 * @stack: ...
 */
void _read(FILE *file, stack_t **stack)
{
	char *line = NULL;
	unsigned int i = 1;
	size_t n = 0;
	int res;
	int (*f)(stack_t **stack, unsigned int line_number);

	while (_getline(&line, &n, file) != -1)
	{
		get_tokens(line);
		if (!argv[0] || strcmp(argv[0], "nop") == 0 || argv[0][0] == '#')
		{
			i++;
			continue;
		}
		f = get_func(argv[0]);
		if (!f)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", i, argv[0]);
			res = -1;
		}
		else
			res = f(stack, i);
		if (res == -1)
			__exit(stack, line, file);
		i++;
		argv[0] = NULL;
	}
	free(line);
}

/**
 * __exit - This function frees memory and exits with failure
 * @stack: Address of the stack
 * @line: string
 * @file: file pointer
 */
void __exit(stack_t **stack, char *line, FILE *file)
{
	free(line);
	free(argv);
	fclose(file);
	free_list(*stack);
	exit(EXIT_FAILURE);
}

/**
 * free_list - This function frees a linked list
 * @stack: Head of the list
 */
void free_list(stack_t *stack)
{
	stack_t *h;

	while (stack)
	{
		h = stack->next;
		free(stack);
		stack = h;
	}
}
