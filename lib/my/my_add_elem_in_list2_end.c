/*
** my_add_elem_in_list2_end.c for my_add_elem_in_list2 in /home/bongol_b/Epitech-rendu/libmy
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Feb 21 22:52:28 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 12 13:54:06 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "mylist.h"

int		my_add_elem_in_list2_end(t_list2 **begin, void *data)
{
  t_list2	*curr;

  curr = *begin;
  if (curr == NULL)
    return (my_add_elem_in_list2_begin(begin, data));
  while (curr->next)
    curr = curr->next;
  curr->next = malloc(sizeof(*curr));
  if (curr->next == NULL)
    return (0);
  curr->next->prev = curr;
  curr->next->data = data;
  curr->next->next = NULL;
  return (1);
}
