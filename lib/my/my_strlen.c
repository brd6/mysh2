/*
** my_strlen.c for my_strlen in /home/bongol_b/rendu/Piscine_C_J04
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Oct  1 09:29:01 2015 berdrigue bongolo-beto
** Last update Fri Jan 15 00:38:08 2016 Berdrigue BONGOLO BETO
*/

#include <stdio.h>

int		my_strlen(char *str)
{
  int		cp;

  cp = 0;
  if (str == NULL || str[0] == 0)
    return (cp);
  while (str[cp])
    cp = cp + 1;
  return (cp);
}
