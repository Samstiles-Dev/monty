#include "monty.h"
/**
  * pp_mul - this function adds the two top elements of the stack
  * @stack:  the head of the stack
  * @number_line: the line number
  */

void pp_mul(stack_t **stack, unsigned int number_line)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", number_line);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	data_temp = *stack;
	g = data_temp->n;
	h = data_temp->next->n;
	data_temp->next->n = g * h;
	*stack = data_temp->next;
	free(data_temp);
}
/**
  * pp_mod - this adds the two top elements of the stack
  * @stack:  the head of the stack
  * @number_line: the line number
  */

void pp_mod(stack_t **stack, unsigned int number_line)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", number_line);
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
	data_temp->next->n = h % g;
	*stack = data_temp->next;
	free(data_temp);
}
