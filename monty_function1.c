#include "monty.h"

/**
  * push_to_stack - adds an element to the top of the stack
  * @stack_data: the first element of a stack
  * @number_line: the line number
  */

void push_to_stack(stack_t **stack_data, unsigned int number_line)
{
	int k = 0, flag = 0, m = 0;

	if (var.value != NULL)
	{
		if (var.value[0] == '-')
		{
			k++;
		}
		for (; var.value[k] != '\0'; k++)
		{
			if (var.value[k] > 57 || var.value[k] < 48)
			{
				flag = 1;
			}
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer to stact\n", number_line);
			fclose(var.file);
			free(var.content);
			free_stack(*stack_data);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", number_line);
		fclose(var.file);
		free(var.content);
		free_stack(*stack_data);
		exit(EXIT_FAILURE);
	}
	m = atoi(var.value);
	add_node(stack_data, m);
}

/**
  * print_stack - prints all the elements on the stack
  * @stack_data: the stack that the element will be added to
  * @number_line: the line number
  */

void print_stack(stack_t **stack_data, unsigned int number_line)
{
	stack_t *temp_stack;

	(void)number_line;
	temp_stack = *stack_data;
	while (temp_stack != NULL)
	{
		printf("%d\n", temp_stack->n);
		temp_stack = temp_stack->next;
	}
}

/**
  * print_top_elem - this prints the element at the top of the stack
  * @stack_data: this is the head of the stack
  * @number_line: this is line number
  */
void print_top_elem(stack_t **stack_data, unsigned int number_line)
{
	stack_t *temp_data;

	temp_data = *stack_data;
	if (temp_data == NULL)
	{
		fprintf(stderr, "L%d: can't print top element, stack empty\n", number_line);
		fclose(var.file);
		free(var.content);
		free_stack(*stack_data);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", temp_data->n);
}

/**
  * pop_elem - removes the top element of the stack
  * @stack_data: this is the head of the stack
  * @number_line: this is the line number
  */
void pop_elem(stack_t **stack_data, unsigned int number_line)
{
	stack_t *temp_data;

	temp_data = *stack_data;
	if (temp_data == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", number_line);
		fclose(var.file);
		free(var.content);
		free_stack(*stack_data);
		exit(EXIT_FAILURE);
	}
	*stack_data = temp_data->next;
	free(temp_data);
}
