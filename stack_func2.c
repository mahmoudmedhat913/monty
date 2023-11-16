#include "monty.h"

/**
 * nop - function
 * @stack: pointer to pointer
 * @line_number: line number of op code
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * swap_nodes - swap top 2 elements
 * @stack: pointer to pointer
 * @line_number: line number of op code
 */

void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *t;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "swap");
	t = (*stack)->next;
	(*stack)->next = t->next;
	if (t->next != NULL)
		t->next->prev = *stack;
	t->next = *stack;
	(*stack)->prev = t;
	t->prev = NULL;
	*stack = t;
}

/**
 * add_nodes - adds top 2 element
 * @stack: pointer to pointer
 * @line_number: line number of op code
 */

void add_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "add");
	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub_nodes - subtract top 2 elements
 * @stack: pointer to pointer
 * @line_number: line number of op code
 */

void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int sub;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "sub");
	(*stack) = (*stack)->next;
	sub = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sub;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_nodes - divide top 2 elements
 * @stack: pointer to pointer
 * @line_number: line number of op code
 */

void div_nodes(stack_t **stack, unsigned int line_number)
{
	int div;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "div");
	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	div = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = div;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
