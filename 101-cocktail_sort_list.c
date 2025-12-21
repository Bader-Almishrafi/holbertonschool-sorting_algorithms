#include "sort.h"
/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @node1: First node
 * @node2: Second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
if (node1->prev)
node1->prev->next = node2;
else
*list = node2;
if (node2->next)
node2->next->prev = node1;
node1->next = node2->next;
node2->prev = node1->prev;
node2->next = node1;
node1->prev = node2;
}
/**
 * cocktail_sort_list - Sorts a doubly linked list using cocktail sort
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
listint_t *current;
int swapped = 1;
if (!list || !*list || !(*list)->next)
return;
while (swapped)
{
swapped = 0;
current = *list;
/* Forward pass */
while (current->next)
{
if (current->n > current->next->n)
{
swap_nodes(list, current, current->next);
print_list(*list);
swapped = 1;
}
else
current = current->next;
}
if (!swapped)
break;
swapped = 0;
/* Backward pass */
while (current->prev)
{
if (current->prev->n > current->n)
{
swap_nodes(list, current->prev, current);
print_list(*list);
swapped = 1;
}
else
current = current->prev;
}
}
}

