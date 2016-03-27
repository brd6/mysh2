/*
** file.c for  in /home/bongol_b/Epitech-rendu/libmy
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
3** Started on  Mon Mar 14 00:38:33 2016 Berdrigue BONGOLO BETO
** Last update Mon Mar 14 01:57:38 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include <stdio.h>
#include "file.h"

void		file_free(t_file *file)
{
  t_file	*curr;
  t_file	*prev;

  if (file == NULL)
    return;
  curr = file->head;
  while (curr != NULL)
    {
      prev = curr;
      curr = curr->next;
      free(prev->data);
      free(prev);
    }
  file->head = NULL;
  file->queue = NULL;
}

int		file_enqueue(t_file *file, void *data)
{
  t_file	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (0);
  new->data = data;
  new->next = NULL;
  if (file->head == NULL)
    {
      file->head = new;
      file->queue = file->head;
    }
  else
    {
      file->queue->next = new;
      file->queue = new;
    }
  return (1);
}

void		*file_dequeue(t_file *file)
{
  t_file	*curr;
  void		*data;

  if (file_is_empty(file))
    return (NULL);
  data = file->head->data;
  curr = file->head;
  file->head = file->head->next;
  free(curr);
  return (data);
}
