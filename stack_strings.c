#include "monty.h"

/**
 * print_char - print ascii value
 * @stack: pointer to pointer
 * @line_number: line number of op code
 */

void print_char(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_number);
	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		string_err(1, line_number);
	printf("%c\n", ascii);
}

/**
 * print_str - print string
 * @stack: pointer to pointer
 * @ln: line number of op code
 */

void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *t;

	if (stack == NULL || *stack ==NULL)
	{
		printf("\n");
		return;
	}
	t = *stack;
	while (t != NULL)
	{
		ascii = t->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		t = t->next;
	}
	printf("\n");
}

/**
 * rotl - rotate first node to bottom
 * @stack: pointer to pointer
 * @ln: line number of op code
 */

void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *t;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	t = *stack;
	while (t->next != NULL)
		t = t->next;
	t->next = *stack;
	(*stack)->prev = t;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotr - rotate last node to top
 * @stack: pointer to pointer
 * @ln: line number of op code
 */

void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *t;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	t = *stack;
	while (t->next != NULL)
		t = t->next;
	t->next = *stack;
	t->prev->next = NULL;
	t->prev = NULL;
	(*stack)->prev = t;
	(*stack) = t;
}
