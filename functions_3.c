#include <stdio.h>
#include "monty.h"

/**
 * pchar - This function prints the top element
 * @stack: Stack list
 * @line_number: Line number
 *
 * Return: ...
 */
int pchar(stack_t **stack, unsigned int line_number)
{
	int n;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		return (-1);
	}
	n = (**stack).n;
	if (!(n >= 0 && n <= 127))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		return (-1);
	}
	printf("%c\n", n);
	return (0);
}
