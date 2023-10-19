#include "monty.h"

/**
  * pp_execute - this function gets the correct op function code and executes
  * @line_num: the name of the operator
  * @stack: the first head of the stack
  * @content: this is the command
  * @file: this is the file descriptor
  * Return: pointer to operation if its found or NULL if not
  */

int pp_execute(char *content, stack_t **stack, unsigned int line_num, FILE *file)
{
	instruction_t func_names[] = {
		{"push", push_to_stack},
		{"pall", print_stack},
		{"pint", print_top_elem},
		{"pop", pop_elem},
		{"swap", swap_elem},
		{"nop", pp_nop},
		{"add", add_to_stack},
		{"sub", pp_sub},
		{"div", pp_div},
		{"mul", pp_mul},
		{"mod", pp_mod},
		{NULL, NULL}
		};
	int i;
	char *_op = NULL;

	_op = strtok(content, " \n\t\r");
	if (_op && _op[0] == '#')
	{
		return (0);
	}
	var.value = strtok(NULL, " \n\t\r");

	i = 0;
	while (func_names[i].opcode && _op != NULL)
	{
		if (strcmp(func_names[i].opcode, _op) == 0)
		{
			func_names[i].f(stack, line_num);
			return (0);
		}
		i++;
	}
	if (_op != NULL && func_names[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, _op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
