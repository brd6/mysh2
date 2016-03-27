/*
** init_file.c for init_file in /home/bongol_b/Epitech-rendu/libmy
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Mar 14 01:57:03 2016 Berdrigue BONGOLO BETO
** Last update Mon Mar 14 01:57:28 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include <stdio.h>
#include "file.h"

t_file		init_file()
{
  t_file	file;

  file.data = NULL;
  file.head = NULL;
  file.next = NULL;
  file.queue = NULL;
  return (file);
}

int		file_is_empty(t_file *file)
{
  return (file->head == NULL);
}

void		*file_head(t_file *file)
{
  return (!file_is_empty(file) ? file->head->data : NULL);
}

void		*file_queue(t_file *file)
{
  return (!file_is_empty(file) ? file->queue->data : NULL);
}
