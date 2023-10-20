#include "monty.h"


/**
 * s_add_to_stack - this adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: the line number of the opcode.
 */
void s_add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *stack_tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	stack_tmp = head;
	head = *new_node;
	head->next = stack_tmp;
	stack_tmp->prev = head;
}


/**
 * s_print_stack - prints all nodes in the stack.
 * @stack: Points to the top node of the stack.
 * @index: the line number of the opcode.
 */
void s_print_stack(stack_t **stack, unsigned int index)
{
	stack_t *stack_tmp;

	(void) index;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	stack_tmp = *stack;
	while (stack_tmp != NULL)
	{
		printf("%d\n", stack_tmp->n);
		stack_tmp = stack_tmp->next;
	}
}

/**
 * s_pop_top - Pop the top node in the stack.
 * @stack: Points to the top node of the stack.
 * @index: the line number of the opcode.
 */
void s_pop_top(stack_t **stack, unsigned int index)
{
	stack_t *stack_tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, index);

	stack_tmp = *stack;
	*stack = stack_tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(stack_tmp);
}

/**
 * s_print_top - Prints the top node of the stack.
 * @stack: Points to the top node of the stack.
 * @index: the line number of the opcode.
 */
void s_print_top(stack_t **stack, unsigned int index)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, index);
	printf("%d\n", (*stack)->n);
}
