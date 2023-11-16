#include "monty.h"

/**
 * op_add - Adds the top two elements of the stack .
 * @top: Pointer to the top of the stack.
 * @value: Unused parameter (required by function pointer type).
 */
void op_add(stack_t **top, unsigned int value)
{
	int val;
	(void)value;

	if (!top || !(*top) || !((*top)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	val = (*top)->n + (*top)->next->n;
	(*top)->next->n = val;
	pop_element(top, value);
}

/**
 * op_sub - sub the top two elements of the stack.
 * @top: Pointer to the top of the stack.
 * @value: Unused parameter (required by function pointer type).
 */
void op_sub(stack_t **top, unsigned int value)
{
	int val;
	(void)value;

	if (!top || !(*top) || !((*top)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	val = (*top)->next->n - (*top)->n;
	(*top)->next->n = val;
	pop_element(top, value);
}

/**
 * op_mul - mul the top two elements of the stack.
 * @top: Pointer to the top of the stack .
 * @value: Unused parameter (required by function pointer type).
 */
void op_mul(stack_t **top, unsigned int value)
{
	int val;
	(void)value;

	if (!top || !(*top) || !((*top)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	val = (*top)->next->n * (*top)->n;
	(*top)->next->n = val;
	pop_element(top, value);
}

/**
 * op_rotl - Rotates the stack to the top.
 * @top: Pointer to the top of the stack.
 * @value: Unused parameter.
 */
void op_rotl(stack_t **top, unsigned int value)
{
	stack_t *tmp;
	(void)value;

	if (!top || !*top || !(*top)->next)
		return;

	tmp = *top;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *top;
	(*top)->prev = tmp;
	*top = (*top)->next;
	(*top)->prev->next = NULL;
	tmp->prev = NULL;
}
