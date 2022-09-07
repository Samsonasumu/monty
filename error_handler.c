#include "monty.h"
/**
 * error_handler - math the correct error message
 * @op_or_error: error code
 * @Linenumber: script line number
 *
 * Return: void
 */
void error_handler(char *op_or_error, unsigned int Linenumber)
{
	size_t i;
	check_valid_erros_z valid_error[] = {
		{"is_not_int", error_isnot_int},
		{"malloc_fails", malloc_fails},
		{"error_add", error_handler_add},
		{"empty_stack", error_empty_stack},
		{"pchar_error", error_pchar},
		{"isnot_assci", isnot_assci},
		{"error_sub", error_sub},
		{"error_pint", error_pint},
		{"error_mod", error_mod},
		{"error_div_by_0", error_div_by_0},
		{"wrong_argu", wrong_arguments},
		{"error_swap", error_swap},
		{"error_div", error_div},
		{"error_mul", error_mul},
		{NULL, NULL}
	};

	for (i = 0; valid_error[i].opcode != NULL; i++)
	{
		if (strcmp(valid_error[i].opcode, op_or_error) == 0)
		{
			valid_error[i].f(Linenumber);
			return;
		}
	}
	dprintf(STDERR_FILENO, "%s: Error Message not in Data Base\n", op_or_error);
	exit(EXIT_FAILURE);
}
