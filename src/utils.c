/*
** utils.c for utils in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Mar 21 00:54:30 2016 Berdrigue BONGOLO BETO
** Last update Mon Mar 21 01:31:35 2016 Berdrigue BONGOLO BETO
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
