#include "monty.h"

/**
 * f_mod - Computes the rest of the division of the second top.
 * @head: Stack Head
 * @counter: Counter
 * Return: Void
 */
void f_mod(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n % h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
