#include "monty.h"
stack_t *head = NULL;

/**
 * main - the main function (entry point)
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create_node - this function creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - this function frees nodes in the stack.
 */
void free_nodes(void)
{
	stack_t *stack_tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		stack_tmp = head;
		head = head->next;
		free(stack_tmp);
	}
}


/**
 * add_to_queue - this func adds a node to the queue.
 * @new_node: Points to the new node.
 * @ln: line number of the opcode.
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	while (stack_tmp->next != NULL)
		stack_tmp = stack_tmp->next;

	stack_tmp->next = *new_node;
	(*new_node)->prev = stack_tmp;

}
