#include "monty.h"

/**
 * check_if_op_match - check if op is a valid operator
 * @op: op to check
 * @stack: double pointer to the beginnig of the stack
 * @Linenumber: script line number
 *
 * Return: void
 */
void check_if_op_match(char *op, stack_t **stack, unsigned int Linenumber)
{
	size_t i;
	instruction_t valid_ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_m},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack_m},
		{"queue", queue},
		{NULL, NULL}
	};

	for (i = 0; valid_ops[i].opcode != NULL; i++)
	{
		if (strcmp(valid_ops[i].opcode, op) == 0)
		{
			valid_ops[i].f(stack, Linenumber);
			return;
		}
	}
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", Linenumber, op);
	exit(EXIT_FAILURE);

}
