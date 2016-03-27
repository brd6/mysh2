/*
** my_getstr_value.c for my_getstr_value in /home/bongol_b/Epitech-rendu/PSU_2015_tetris/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Mar  4 13:01:08 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 12 14:03:38 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"

char		*my_getstr_value(char *str, char separator)
{
  char		*value;
  int		i;
  int		j;

  if ((value = malloc(sizeof(*value) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (str[i] && str[i] != separator)
    i++;
  i++;
  while (str[i])
    value[j++] = str[i++];
  value[j] = 0;
  return (value);
}
