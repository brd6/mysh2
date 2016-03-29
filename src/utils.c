/*
** utils.c for utils in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Mar 21 00:54:30 2016 Berdrigue BONGOLO BETO
** Last update Tue Mar 29 10:43:54 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"

int		check_null_line(char *line)
{
  if (line == NULL)
    {
      my_putstr("exit\n");
      return (0);
    }
  return (1);
}

int		is_space_str(char *str)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (1);
  while (str[i])
    {
      if (str[i] != ' ')
	return (0);
      i++;
    }
  return (1);
}
