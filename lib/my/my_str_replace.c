/*
** my_str_replace.c for my_str_replace in /home/bongol_b/rendu/PSU_2015_minishell1
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Jan 14 12:46:38 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 12 14:02:08 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"

int		count_occurence(char *search, char *subject, int n, int *cp2)
{
  int		cp;
  char		*s;

  cp = 0;
  s = my_strstr(subject, search);
  while (s)
    {
      cp++;
      if (n > 1 && cp == n)
	break;
      s = my_strstr(s + my_strlen(search), search);
    }
  *cp2 = 0;
  return (cp);
}

char		*my_str_replace(char *search, char *replace, char *subject,
				int n)
{
  int		size;
  char		*str;
  char		*old;
  char		*s;
  int		cp;

  size = count_occurence(search, subject, n, &cp);
  size = (my_strlen(replace) - my_strlen(search)) * size + my_strlen(subject);
  if ((str = malloc(sizeof(*str) * (size + 1))) == NULL)
    return (NULL);
  my_strcpy(str, "");
  old = subject;
  s = my_strstr(subject, search);
  while (s)
    {
      my_strncpy(str + my_strlen(str), old, s - old);
      my_strcpy(str + my_strlen(str), replace);
      old = s + my_strlen(search);
      s = my_strstr(s + my_strlen(search), search);
      if (n > 1 && cp == n)
	break;
      cp++;
    }
  my_strcpy(str + my_strlen(str), old);
  return (str);
}
