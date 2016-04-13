/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/bongol_b/rendu/Piscine_C_J08/ex_04
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Wed Oct  7 17:38:23 2015 berdrigue bongolo-beto
** Last update Wed Apr 13 07:53:26 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"

int	is_word_pos(char *str, int i, int start)
{
  if ((is_alpha(str[i]) || is_num(str[i])) && start)
    {
      if (!i || !(is_alpha(str[i - 1]) || is_num(str[i - 1])))
	return (1);
    }
  else if (!(is_alpha(str[i]) || is_num(str[i])) && !start)
    {
      if (i && (is_alpha(str[i - 1]) || is_num(str[i - 1])))
	return (1);
    }
  return (0);
}

int	tabwords_count(char *str)
{
  int	i;
  int	words_cp;

  i = 0;
  words_cp = 0;
  while (str[i])
    {
      if (is_word_pos(str, i, 1))
	words_cp = words_cp + 1;
      i = i + 1;
    }
  return (words_cp);
}

char	*strcpy_at(char *str, char *dest, int start_pos)
{
  int	i;
  int	end_pos;

  i = start_pos;
  while (str[i])
    {
      if (is_word_pos(str, i, 0))
	  break;
      i = i + 1;
    }
  if (i >= my_strlen(str))
    end_pos = my_strlen(str);
  else
    end_pos = i;
  i = 0;
  dest = malloc(end_pos - start_pos + 1);
  if (dest == NULL)
    return (NULL);
  while (start_pos < end_pos)
  {
    dest[i] = str[start_pos];
    start_pos = start_pos + 1;
    i = i + 1;
  }
  return (dest);
}

void	wordtab_cpy(char *str, char **dest)
{
  int	i;
  int	cp;
  int	start_pos;

  i = 0;
  cp = 0;
  start_pos = 0;
  while (str[i])
    {
      if (is_word_pos(str, i, 1))
	{
	  start_pos = 1;
	  dest[cp] = strcpy_at(str, dest[cp], start_pos);
	  cp = cp + 1;
	}
      i = i + 1;
    }
  dest[cp] = 0;
}

char	**my_str_to_wordtab(char *str)
{
  int	tab_len;
  char	**str_cp;

  return (my_str_split(str, " "));
  tab_len = tabwords_count(str);
  str_cp = malloc(sizeof(*str_cp) * (tab_len + 1));
  if (str_cp == NULL)
    return (NULL);
  wordtab_cpy(str, str_cp);
  return (str_cp);
}
