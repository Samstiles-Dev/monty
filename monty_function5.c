#include "monty.h"

/**
 * parse_line - Separates each line into tokens
 * @buffer: line from the file
 * @index: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parse_line(char *buffer, int index, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, value, index, format);
	return (format);
}

/**
 * open_file - this function opens a file
 * @f_name: the name of the file
 * Return: void
 */
void open_file(char *f_name)
{
	FILE *fd = fopen(f_name, "r");

	if (f_name == NULL || fd == NULL)
		err(2, f_name);

	read_file(fd);
	fclose(fd);
}


/**
 * find_func - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_func(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", s_add_to_stack},
		{"pall", s_print_stack},
		{"pint", s_print_top},
		{"pop", s_pop_top},
		{"nop", s_nop},
		{"swap", s_swap_nodes},
		{"add", s_add_nodes},
		{"sub", s_sub_nodes},
		{"div", s_div_nodes},
		{"mul", s_mul_nodes},
		{"mod", s_mod_nodes},
		{"pchar", s_print_char},
		{"pstr", s_print_str},
		{"rotl", s_rotl},
		{"rotr", s_rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, ln, opcode);
}


/**
 * call_fun - Calls the needed function.
 * @func: Points to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int k;
	int flag;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (k = 0; val[k] != '\0'; k++)
		{
			if (isdigit(val[k]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}

/**
 * read_file - this function reads a file to output
 * @fd: points to the file descriptor
 * Return: void
 */

void read_file(FILE *fd)
{
	int index, format = 0;
	char *buffer = NULL;
	size_t lenght = 0;

	for (index = 1; getline(&buffer, &lenght, fd) != -1; index++)
	{
		format = parse_line(buffer, index, format);
	}
	free(buffer);
}
