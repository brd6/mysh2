/*
** my_eput_str.c for my_epur_str in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Mar 27 00:06:10 2016 Berdrigue BONGOLO BETO
** Last update Sun Mar 27 13:59:57 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"

int		skip_char(char *str, char *s)
{
  int		i;

  i = 0;
  while (my_get_char_pos(s, str[i]) != -1)
    i++;
  return (i);
}

char		*my_epur_str(char *str, char *to_remove, int replace_with_space)
{
  int		i;
  char		*new_str;
  int		j;
  int		str_len;

  if ((new_str = malloc(sizeof(*str) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  i = skip_char(str, to_remove);
  j = 0;
  str_len = my_strlen(str);
  while (str[i])
    {
      if (my_get_char_pos(to_remove, str[i]) == -1)
	{
	  new_str[j] = str[i];
	  if (i + 2 < str_len && my_get_char_pos(to_remove, str[i + 1]) != -1)
	    new_str[++j] = (replace_with_space) ? ' ' : str[i + 1];
	  j++;
	}
      i++;
    }
  new_str[j] = 0;
  return (new_str);
}
