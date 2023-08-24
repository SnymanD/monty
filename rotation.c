#include "monty.h"

/**
 *f_rotr- Rotates the stack to the bottom.
 *@head: Stack Head
 *@counter: ...
 *Return: Nothing
 */

void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *cp = *head;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (cp->next)
	{
		cp = cp->next;
	}
	cp->next = *head;
	cp->prev->next = NULL;
	cp->prev = NULL;
	(*head)->prev = cp;
	(*head) = cp;
}
