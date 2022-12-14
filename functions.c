#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "monty.h"

/**
 * swap - This function pops top element in a stack
 * @stack: Stack list
 * @line_number: Line number
 *
 * Return: ...
 */
int swap(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;
	int i = 0;

	if (!h || !h->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		return (-1);
	}
	h = *stack;
	i = h->n;
	h->n = h->next->n;
	h->next->n = i;
	return (0);
}

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
	h = *stack;
	*stack = (**stack).next;
	free(h);
	if (*stack)
		(**stack).prev = NULL;
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
	while (argv[1][i])
	{
		if (argv[1][i] == '-' && i == 0)
		{
			i++;
			continue;
		}
		if (!isdigit(argv[1][i]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			return (-1);
		}
		i++;
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
	{
		(**stack).prev = new;
		new->next = *stack;
	}
	*stack = new;
	if (stacks == 0)
		rotl(stack, line_number);
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
