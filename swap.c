#include "monty.h"

/**
 * f_swap - Adds the top two elements of the stack.
 * @head: Stack Head
 * @counter: ...
 * Return: Nothing
 */
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len, aux;

	h = *head;
	len = 0;

	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
