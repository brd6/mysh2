/*
** my_strchr.c for my_strchr in /home/bongol_b/rendu/Piscine_C_bistromathique
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Oct 25 21:47:50 2015 berdrigue bongolo-beto
** Last update Mon Dec 28 13:29:00 2015 berdrigue bongolo-beto
*/

#include <stdlib.h>

char	*my_strchr(char *s, char c)
{
  int	i;

  i = 0;
  while (*s && *s != c)
    {
      s = s + 1;
      i = i + 1;
    }
  if (*s == '\0')
    return (NULL);
  else
    return (s);
}
