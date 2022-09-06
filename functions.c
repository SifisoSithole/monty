#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * push - This function pushes an element into the stack
 * @stack: Stack list
 * @line_number: Line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; argv[1][i]; i++)
	{
		if (!(argv[1][i] >= 48 && argv[1][i] <= 57))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	new->n = atoi(argv[1]);
	new->prev = NULL;
	if (!stack || !*stack)
		new->next = NULL;
	else
		new->next = *stack;
	*stack = new;
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	(void) line_number;
	if (!stack || !*stack)
		return;

	h = *stack;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
