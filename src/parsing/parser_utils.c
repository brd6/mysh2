/*
** parser_utils.c for parser_utils in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Mar 31 11:58:42 2016 Berdrigue BONGOLO BETO
** Last update Thu Mar 31 12:22:13 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"
#include "parser.h"

static int	get_list_str_size(t_list2 *list)
{
  int		i;
  t_list2	*curr;
  t_parser	*parser;

  i = 0;
  curr = list;
  while (curr != NULL)
    {
      parser = ((t_parser *)(list->data));
      i += my_strlen(parser->token) + 2;
      curr = curr->next;
    }
  return (i + 1);
}

char		*parser_list_to_str(t_list2 *list)
{
  t_list2	*curr;
  char		*str;
  t_parser	*parser;

  curr = list;
  if (curr == NULL)
    return (NULL);
  if ((str = malloc(sizeof(*str) * (get_list_str_size(list) + 1))) == NULL)
    return (NULL);
  while (curr->next != NULL)
    curr = curr->next;
  str[0] = 0;
  while (curr != NULL)
    {
      parser = ((t_parser *)(curr->data));
      str = my_strcat(str, parser->token);
      if (curr->prev != NULL &&
	  parser->token[my_strlen(parser->token) - 1] != ' ')
	str = my_strcat(str, " ");
      curr = curr->prev;
    }
  return (str);
}
