#include "monty.h"


/**
 * main - Monty bytecode interpreter
 * @argc: numbers of arguments passed
 * @argv: arrays of argument
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure
 */

int main(int argc, char *argv[])
{
	stack_t *stack_list = NULL;
	unsigned int Linemunber = 0;
	FILE *FILE = NULL;
	char *File_line = NULL, *operator = NULL;
	size_t len_buffer = 0;
	/*QUEUE and numbers of nodes from stack*/
	var.queue = 0;
	var.stack_len = 0;
	/* Make sure get two arguments*/
	if (argc != 2)
	{
		error_handler("wrong_argu", Linemunber);
	}
	/*reading file*/
	FILE = fopen(argv[1], "r");
	if (FILE == NULL)
	{
		error_fopen(argv[1]);
	}
	/*on_exit functions get active at program termination: Cleaner*/
	on_exit(free_File_line, &File_line);
	on_exit(free_stack_list, &stack_list);
	on_exit(close_File, FILE);
	while (getline(&File_line, &len_buffer, FILE) != -1)
	{
		/* Here we process file content and its validations*/
		Linemunber++;
		operator = strtok(File_line, "\n\t\r ");
		if (operator != NULL && operator[0] != '#')
		{
			check_if_op_match(operator, &stack_list, Linemunber);
		}
	}
	exit(EXIT_SUCCESS);
}
