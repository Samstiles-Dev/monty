#include "monty.h"

/**
  * swap_elem - this function swaps the top two elements on the stack
  * @stack: this is the head of the stack
  * @number_line: ths is the line number
  */

void swap_elem(stack_t **stack, unsigned int number_line)
{
	stack_t *data_temp;
	int len_value = 0, n;

	data_temp = *stack;
	while (data_temp != NULL)
	{
		data_temp = data_temp->next;
		len_value++;
	}

	if (len_value < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", number_line);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	data_temp = *stack;
	n = data_temp->n;
	data_temp->n = data_temp->next->n;
	data_temp->next->n = n;
}

/**
  * add_to_stack - this function adds the two top elements of the stack
  * @stack:  this is the head of the stack
  * @number_line: this is te line number
  */

void add_to_stack(stack_t **stack, unsigned int number_line)
{
	stack_t *data_temp;
	int len_value = 0, g, h;

	data_temp = *stack;
	while (data_temp != NULL)
	{
		data_temp = data_temp->next;
		len_value++;
	}

	if (len_value < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", number_line);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	data_temp = *stack;
	g = data_temp->n;
	h = data_temp->next->n;
	data_temp->next->n = g + h;
	*stack = data_temp->next;
	free(data_temp);
}

/**
  * pp_nop - this doesn't do anything
  * @stack: this is the head of the stack
  * @number_line: this is the line number
  */
void pp_nop(stack_t **stack, unsigned int number_line)
{
	(void)stack;
	(void)number_line;
}

/**
  * pp_sub - this function subtract the two top elements of the stack
  * @stack:  this is the head of the stack
  * @number_line: this is te line number
  */

void pp_sub(stack_t **stack, unsigned int number_line)
{
	stack_t *data_temp;
	int len_value = 0, g, h;

	data_temp = *stack;
	while (data_temp != NULL)
	{
		data_temp = data_temp->next;
		len_value++;
	}

	if (len_value < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", number_line);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	data_temp = *stack;
	g = data_temp->n;
	h = data_temp->next->n;
	data_temp->next->n = h - g;
	*stack = data_temp->next;
	free(data_temp);
}
/**
  * pp_div - this divide the two top elements of the stack
  * @stack:  this is the head of the stack
  * @number_line: this is te line number
  */

void pp_div(stack_t **stack, unsigned int number_line)
{
	stack_t *data_temp;
	int len_value = 0, g, h;

	data_temp = *stack;
	while (data_temp != NULL)
	{
		data_temp = data_temp->next;
		len_value++;
	}

	if (len_value < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", number_line);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	data_temp = *stack;
	if (data_temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", number_line);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	g = data_temp->n;
	h = data_temp->next->n;
	data_temp->next->n = h / g;
	*stack = data_temp->next;
	free(data_temp);
}
