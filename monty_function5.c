#include "monty.h"

/**
  * free_stack - this function frees all the elements of the stack
  * @head: the head of the stack
  */

void free_stack(stack_t *head)
{
	stack_t *data_temp;

	data_temp = head;

	while (data_temp != NULL)
	{
		data_temp = data_temp->next;
		free(head);
		head = data_temp;
	}
}

/**
  * pp_add_node - this function adds a new element at the top of a stack
  * @head: this is the first element on the stack
  * @n: this is the value that will be added to the stack
  */
void pp_add_node(stack_t **head, const int n)
{
	stack_t *new_node, *data_temp;

	data_temp = *head;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->prev = NULL;
	new_node->n = n;
	if (data_temp)
	{
		data_temp->prev = new_node;
	}
		new_node->next = *head;
		*head = new_node;
}
