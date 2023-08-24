#include "monty.h"

/**
 *f_sub- The Sustration
 *@head: Stack Head
 *@counter: ...
 *Return: Nothing
 */

void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int x, y;

	aux = *head;
	for (y = 0; aux != NULL; y++)
		aux = aux->next;
	if (y < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	x = aux->next->n - aux->n;
	aux->next->n = x;
	*head = aux->next;
	free(aux);
}
