/*
** utils.c for utils in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Mar 21 00:54:30 2016 Berdrigue BONGOLO BETO
** Last update Sun Apr  3 15:27:59 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int		check_null_line(char *line)
{
  if (line == NULL)
    return (my_putstr(EXIT_MSG), 0);
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

char		*concat_two_str(char *str1, char *str2, char *c)
{
  char		*tmp;

  if ((tmp = malloc(my_strlen(str1) + my_strlen(str2) + 2)) == NULL)
    return (0);
  tmp[0] = 0;
  if (str1[my_strlen(str1) - 1] != c[0])
    {
      my_strcat(tmp, str1);
      my_strcat(tmp, c);
      tmp[my_strlen(str1) + 1] = 0;
    }
  else
    {
      my_strcat(tmp, str1);
      tmp[my_strlen(str1)] = 0;
    }
  my_strcat(tmp, str2);
  tmp[my_strlen(str1) + my_strlen(str2) + 1] = 0;
  return (tmp);
}
