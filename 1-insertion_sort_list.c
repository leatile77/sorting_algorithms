#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * node_swap - Function that swaps two nodes of a given doubly linked list.
 * @head: List containing nodes to swap.
 * @swp1: First node to swap.
 * @swp2: Second node to swap.
 *
 * Return: void
 */

void node_swap(listint_t **head, listint_t *swp1, listint_t *swp2)
{
swp1->next = swp2->next;
if (swp1->next != NULL)
{
swp2->next->prev = swp1;
}
swp2->prev = swp1->prev;
swp2->next = swp1;

if (swp1->prev == NULL)
{
*head = swp2;
}
else
{
swp1->prev->next = swp2;
}

swp1->prev = swp2;
swp1 = swp2->prev;

}

/**
 * insertion_sort_list - Function that performs insertion sort
 * on a doubly linked list of integers.
 * @list: list integers to sort.
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
listint_t *curr, *nxt, *prv;

if (list == NULL || *list == NULL || (*list)->next == NULL)
{
return;
}

for (curr = (*list)->next; curr != NULL;)
{
nxt = curr->next;
prv = curr->prev;

if (prv != NULL && curr->n < prv->n)
{
node_swap(list, prv, curr);
print_list(*list);
}
else
{
curr = nxt;
}
}
}
