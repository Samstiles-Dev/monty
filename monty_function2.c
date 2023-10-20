#include "monty.h"

/**
 * s_nop - Does nothing.
 * @stack: Points to top node of the stack.
 * @index: the line number of the opcode.
 */
void s_nop(stack_t **stack, unsigned int index)
{
	(void)stack;
	(void)index;
}


/**
 * s_swap_nodes - Swaps the top two elements of the stack.
 * @stack: Points to the top node of the stack.
 * @index: the line number of the opcode.
 */
void s_swap_nodes(stack_t **stack, unsigned int index)
{
	stack_t *stack_tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, index, "swap");
	stack_tmp = (*stack)->next;
	(*stack)->next = stack_tmp->next;
	if (stack_tmp->next != NULL)
		stack_tmp->next->prev = *stack;
	stack_tmp->next = *stack;
	(*stack)->prev = stack_tmp;
	stack_tmp->prev = NULL;
	*stack = stack_tmp;
}

/**
 * s_add_nodes - Adds the top two elements of the stack.
 * @stack: Points to the top node of the stack.
 * @index: the line number of the opcode.
 */
void s_add_nodes(stack_t **stack, unsigned int index)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, index, "add");

	(*stack) = (*stack)->next;
	result = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * s_sub_nodes - Subs the top two elements of the stack.
 * @stack: Points to top node of the stack.
 * @index: the line number of the opcode.
 */
void s_sub_nodes(stack_t **stack, unsigned int index)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, index, "sub");


	(*stack) = (*stack)->next;
	result = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * s_div_nodes - Divide the top two elements of the stack.
 * @stack: Points to top node of the stack.
 * @index: the line number of the opcode.
 */
void s_div_nodes(stack_t **stack, unsigned int index)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, index, "div");

	if ((*stack)->n == 0)
		more_err(9, index);
	(*stack) = (*stack)->next;
	result = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
