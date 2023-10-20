#include "monty.h"

/**
 * s_mul_nodes - Multiply the top two elements of the stack.
 * @stack: Points to top node of the stack.
 * @index: the line number of the opcode.
 */
void s_mul_nodes(stack_t **stack, unsigned int index)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, index, "mul");

	(*stack) = (*stack)->next;
	result = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * s_mod_nodes - Modulus of the top two elements of the stack.
 * @stack: Points to top node of the stack.
 * @index: the line number of the opcode.
 */
void s_mod_nodes(stack_t **stack, unsigned int index)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, index, "mod");


	if ((*stack)->n == 0)
		more_err(9, index);
	(*stack) = (*stack)->next;
	result = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
