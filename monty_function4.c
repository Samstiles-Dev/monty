#include "monty.h"


/**
 * s_print_str - Prints a string.
 * @stack: Points to the top node of the stack.
 * @ln: the line number of of the opcode.
 */
void s_print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int result;
	stack_t *stack_tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	stack_tmp = *stack;
	while (stack_tmp != NULL)
	{
		result = stack_tmp->n;
		if (result <= 0 || result > 127)
			break;
		printf("%c", result);
		stack_tmp = stack_tmp->next;
	}
	printf("\n");
}

/**
 * s_rotl - Rotates the first node of the stack to the bottom.
 * @stack: Points to top node of the stack.
 * @ln: the line number of of the opcode.
 */
void s_rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *stack_tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	stack_tmp = *stack;
	while (stack_tmp->next != NULL)
		stack_tmp = stack_tmp->next;

	stack_tmp->next = *stack;
	(*stack)->prev = stack_tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * s_rotr - Rotates the last node of the stack to the top.
 * @stack: Points to top node of the stack.
 * @ln: the line number of of the opcode.
 */
void s_rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *stack_tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	stack_tmp = *stack;

	while (stack_tmp->next != NULL)
		stack_tmp = stack_tmp->next;

	stack_tmp->next = *stack;
	stack_tmp->prev->next = NULL;
	stack_tmp->prev = NULL;
	(*stack)->prev = stack_tmp;
	(*stack) = stack_tmp;
}


/**
 * s_print_char - Prints the result value.
 * @stack: Points to the top node of the stack.
 * @index: the line number of of the opcode.
 */
void s_print_char(stack_t **stack, unsigned int index)
{
	int result;

	if (stack == NULL || *stack == NULL)
		string_err(11, index);

	result = (*stack)->n;
	if (result < 0 || result > 127)
		string_err(10, index);
	printf("%c\n", result);
}
