#include "monty.h"

/**
 * handle_pchar - prints the character at the top of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void handle_pchar(stack_t **head, unsigned int counter)
{
    int value = (*head)->n;
    
    if (*head == NULL)
    {
        fprintf(stderr, "L%u: can't pchar, stack empty\n", counter);
        free_all(head);
    }
    
    if (value < 0 || value > 127)
    {
        fprintf(stderr, "L%u: can't pchar, value out of range\n", counter);
        free_all(head);
    }

    printf("%c\n", (char)value);
}
