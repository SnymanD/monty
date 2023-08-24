#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - Monty code interpreter
 * @argc: Arguments Count
 * @argv: Argument Vector
 * Return: Always 0 on (SUCCESS)
 */

int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size;
	ssize_t readLine;
	stack_t *stack;
	unsigned int count;

	size = 0;
	readLine = 1;
	stack = NULL;
	count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (readLine > 0)
	{
		content = NULL;
		readLine = getline(&content, &size, file);
		bus.content = content;
		count++;
		if (readLine > 0)
		{
			execute(content, &stack, count, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
