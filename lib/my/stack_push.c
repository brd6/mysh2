/*
** stack_push.c for my_stack_push in /home/bongol_b/rendu/Piscine_C_evalexpr
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Oct 25 16:15:54 2015 berdrigue bongolo-beto
** Last update Mon Mar 14 00:07:38 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "mylist.h"

int		stack_push(t_list **stack, void *data)
{
  t_list        *prec;
  int		i;

  i = 0;
  if ((prec = malloc(sizeof(*prec))) == NULL)
    return (0);
  if (my_list_size(*stack) == 0)
    {
      prec->data = data;
      prec->next = NULL;
      *stack = prec;
    }
  else
    {
      prec->data = data;
      prec->next = *stack;
      *stack = prec;
    }
  return (1);
}
