#ifndef MONTY_H
#define MONTY_H

#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        int (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char **argv;

void __exit(stack_t **stack, char *line, FILE *file);

void free_list(stack_t *stack);

int swap(stack_t **stack, unsigned int line_number);

int add(stack_t **stack, unsigned int line_number);

int pint(stack_t **stack, unsigned int line_number);

int pop(stack_t **stack, unsigned int line_number);

int pall(stack_t **stack, unsigned int line_number);

int push(stack_t **stack, unsigned int line_number);

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

void _read(FILE *f, stack_t **stack);

#endif /* MONTY_H */
