#include "simple_shell.h"

/**
 * free_list - Realease the memory allocated for a list
 *
 * @head: A pointer to the first node of the list to free
 */
void free_list(list_t *head)
{
    list_t *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp->str);
        temp->next = NULL;
        free(temp);
    }
}

