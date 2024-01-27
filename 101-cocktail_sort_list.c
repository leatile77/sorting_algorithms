#include <stdio.h>
#include <stdlib.h>
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
if (!swp1 || !swp2 || swp1 == swp2)
  return;

if (swp1->prev)
{
swp1->prev->next = swp2;
}

 else
   {
     *head = swp2;
   }

if (swp2->next)
{
swp2->next->prev = swp1;
}

swp1->next = swp2->next;
swp2->prev = swp1->prev;
swp2->next = swp1;
swp1->prev = swp2;

}


void cocktail_sort_list(listint_t **list)
{
  listint_t *start, *end, *current, *curr;
  int swap_chk;
  
  swap_chk = 1;
  start = *list;
  current = start;
  if (list == NULL || (*list) == NULL || (*list)->next == NULL)
    {
      return;
    }

  for (end = *list; end->next != NULL; )
    {
      end = end->next;
    }
  
  while (swap_chk) 
    {
      swap_chk = 0;

      if (current == end)
	{
	  for (curr = current; curr != NULL && curr != start->prev; curr = curr->prev)
	    {
	      if (curr->n < curr->prev->n)
		{
		  node_swap(list, curr->prev, curr);
		  swap_chk = 1;
		  print_list(*list);

		  if (curr == start->next)
		    {
		      current = start;
		    }
		  else
		    current = curr;
		  break;
		}
	      
	    }
	}
  
      else
  	{
	  for (curr = current; curr != NULL && curr != end->next; curr = curr->next)
	    {
	      if (curr->n > curr->next->n)
		{
		  node_swap(list, curr, curr->next);
		  print_list(*list);
		  swap_chk = 1;

		  if (curr == end->prev)
		    {
			  current = end;
		    }
		  else
		    current = curr;
		  break;
		}
	      
	    }
	}
  
    }
}
 
