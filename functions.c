#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pop - This function pops top element in a stack
 * @stack: Stack list
 * @line_number: Line number
 *
 * Return: ...
 */
int pop(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		return (-1);
	}
	h = (**stack).next;
	free(*stack);
	*stack = h;
	return (0);
}

/**
 * pint - This function pushes an element into the stack
 * @stack: Stack list
 * @line_number: Line number
 *
 * Return: ...
 */
int pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		return (-1);
	}
	printf("%d\n", (**stack).n);
	return (0);
}

/**
 * push - This function pushes an element into the stack
 * @stack: Stack list
 * @line_number: Line number
 *
 * Return: ...
 */
int push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int i = 0;

	if (!argv[1])
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		return (-1);
	}
	if (argv[1][0] == '-')
		i = 1;
	for (; argv[1][i]; i++)
	{
		if (!(argv[1][i] >= 48 && argv[1][i] <= 57))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			return (-1);
		}
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (-1);
	}
	new->n = atoi(argv[1]);
	new->prev = NULL;
	if (!stack || !*stack)
		new->next = NULL;
	else
		new->next = *stack;
	*stack = new;
	return (0);
}

/**
 * pall - This function prints list
 * @stack: ...
 * @line_number: ...
 *
 * Return: ...
 */
int pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	(void) line_number;
	if (!stack || !*stack)
		return (0);

	h = *stack;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	return (0);
}
