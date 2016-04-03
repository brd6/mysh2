/*
** my_list_to_array.c for my_list_to_array in /home/bongol_b/Epitech-rendu/libmy/lib/my
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Feb 21 16:45:40 2016 Berdrigue BONGOLO BETO
** Last update Sun Apr  3 14:55:24 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"

char		**my_list_to_wordtab(t_list *begin)
{
  char		**array;
  int		j;
  t_list	*curr;

  array = malloc(sizeof(*array) * (my_list_size(begin) + 2));
  if (array == NULL)
    return (NULL);
  curr = begin;
  j = 0;
  while (curr)
    {
      array[j++] = my_strdup((char *)curr->data);
      curr = curr->next;
    }
  array[j] = NULL;
  return (array);
}
