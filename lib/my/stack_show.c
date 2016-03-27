/*
** stack_show.c for stack_show in /home/bongol_b/rendu/Piscine_C_bistromathique
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Oct 27 22:32:15 2015 berdrigue bongolo-beto
** Last update Sat Mar 12 14:05:57 2016 Berdrigue BONGOLO BETO
*/

#include "my.h"
#include "mylist.h"

void	stack_show(t_list *stack, char type)
{
  t_list	*curr;

  curr = stack;
  while (curr && curr->data != 0)
    {
      my_putchar('[');
      if (type == 's')
	my_putstr((char *)curr->data);
      else if (type == 'c')
	my_putchar(*((char*)curr->data));
      else if (type == 'i')
	my_put_nbr((*(int *)curr->data));
      my_putstr("]\n");
      curr = curr->next;
    }
}
