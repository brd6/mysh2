/*
** check_valid_line.c for check_valid_line in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Mar 21 01:17:35 2016 Berdrigue BONGOLO BETO
** Last update Sun Mar 27 04:01:24 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"
#include "parser.h"

int		check_token(t_list2 *list, char *str)
{
  if (check_command(list, str))
    return (TOKEN_COMMAND);
  if (check_option(list, str))
    return (TOKEN_OPTION);
  if (check_operator(list, str))
    return (TOKEN_OPERATOR);
  return (TOKEN_UNKNOWN);
}

void		add_to_cmd_list(t_list2 *list, char *str)
{
  printf("%s\n", str);
}

int		check_valid_line(char *line)
{
  int		i;
  char		**tab_line;
  t_list2	*list;
  int		token_type;

  i = 0;
  line = my_epur_str(line, " \t", 1);
  line = my_epur_str(line, ";", 0);
  tab_line = my_str_split(line, " ");
  while (tab_line[i])
    {
      if ((token_type = check_token(list, tab_line[i])) != TOKEN_UNKNOWN)
	{
	  add_to_cmd_list(list, tab_line[i]);
	}
      else
	{
	}
      i++;
    }
  my_free_wordtab(tab_line);
  free(line);
  return (0);
}
