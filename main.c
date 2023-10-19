#include "monty.h"

var_t var = {NULL, NULL, NULL};

/**
  * main - main fuunction (entry point)
  * @argc: the number of command line arguments passed
  * @argv: a string that contains all the arguments
  * Return: always 0
  */

int main(int argc, char **argv)
{
	FILE *file;
	stack_t *stack;
	size_t _line_num = 0;
	char *_line_content;
	size_t size = 0;
	int readline = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	var.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		_line_content = NULL;
		readline = getline(&_line_content, &size, file);
		var.content = _line_content;
		_line_num++;
		if (readline == -1)
		{
			free(_line_content);
			break;
		}
		pp_execute(_line_content, &stack, _line_num, file);
		free(_line_content);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
