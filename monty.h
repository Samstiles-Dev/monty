#ifndef _MONTY_H_
#define _MONTY_H_
#define  _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: this points to the previous element of the stack (or queue)
 * @next: this points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
  * var_t - this contains the value, file and line content
  * @value: this is the value to be added
  * @file: this is  a pointer to monty file
  * @content: this is the content of a line
  *
  * Description - carries values through the program
  */

typedef struct vars_t
{
	char *value;
	FILE *file;
	char *content;
} var_t;

extern var_t var;
int (*get_op_func(char *s))(stack_t, unsigned int);
void free_stack(stack_t *head);
void pp_add_node(stack_t **head, const int n);
int pp_execute(char *content, stack_t **stack, unsigned int line_num, FILE *file); 
void push_to_stack(stack_t **stack_data, unsigned int number_line);
void print_stack(stack_t **stack_data, unsigned int number_line);
void print_top_elem(stack_t **stack_data, unsigned int number_line);
void pop_elem(stack_t **stack_data, unsigned int number_line);
void add_to_stack(stack_t **stack, unsigned int number_line);
void swap_elem(stack_t **stack, unsigned int number_line);
void pp_nop(stack_t **stack, unsigned int number_line);
void pp_sub(stack_t **stack, unsigned int number_line);
void pp_div(stack_t **stack, unsigned int number_line);
void pp_mul(stack_t **stack, unsigned int number_line);
void pp_mod(stack_t **stack, unsigned int number_line);


#endif /* _MONTY_H */
