/*
** my_getstr_key.c for my_getstr_key in /home/bongol_b/Epitech-rendu/PSU_2015_tetris/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Mar  4 12:59:12 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 12 14:07:05 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"

char		*my_getstr_key(char *str, char separator)
{
  char		*key;
  int		i;

  if ((key = malloc(sizeof(*key) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (str[i] && str[i] != separator)
    {
      key[i] = str[i];
      i++;
    }
  key[i] = 0;
  return (key);
}
