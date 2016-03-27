/*
** my_strcat.c for my_strcat in /home/bongol_b/rendu/Piscine_C_J07
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Wed Oct  7 00:09:50 2015 berdrigue bongolo-beto
** Last update Wed Feb 10 13:42:22 2016 Berdrigue BONGOLO BETO
*/

#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	dest_len;
  int	i;

  i = 0;
  dest_len = my_strlen(dest);
  while (src && src[i])
    {
      dest[i + dest_len] = src[i];
      i = i + 1;
    }
  dest[i + dest_len] = 0;
  return (dest);
}
