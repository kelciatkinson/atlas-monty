#include "monty.h"

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (line_number)
	{
    	while (current != NULL)
    	{
    		printf("%d\n", current->n);
        	current = current->next;
    	}
	}
}