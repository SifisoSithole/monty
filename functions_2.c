#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * add - This function adds top 2 element in a stack
 * @stack: Stack list
 * @line_number: Line number
 *
 * Return: ...
 */
int add(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack, *temp;

	if (!h || !h->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		return (-1);
	}

	h->n = h->n + h->next->n;
	temp = h->next;
	h->next = h->next->next;
	free(temp);
	return (0);
}

