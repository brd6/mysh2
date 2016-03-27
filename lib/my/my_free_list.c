/*
** my_free_list.c for my_free_list in /home/bongol_b/Epitech-rendu/libmy
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Feb 21 18:34:00 2016 Berdrigue BONGOLO BETO
** Last update Mon Mar 21 00:43:33 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "mylist.h"

void		my_free_list(t_list **begin)
{
  t_list	*curr;

  while (*begin)
    {
      curr = *begin;
      *begin = (*begin)->next;
      free(curr->data);
      free(curr);
    }
  *begin = NULL;
}
