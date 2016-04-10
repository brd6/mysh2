/*
** check_valid_line.c for check_valid_line in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Mar 21 01:17:35 2016 Berdrigue BONGOLO BETO
** Last update Sun Apr 10 12:25:42 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"
#include "parser.h"
#include "mysh.h"

t_list		*check_valid_line(char *line)
{
  int		i;
  char		**tab_line;
  t_list2	*list;
  int		ttype;
  int		j;
  char		*str_cmd;
  t_parser	*parser;

  if ((list = parsing_line(line)) == NULL)
    return (NULL);

  // delete unless ; in list's end
  parser = (t_parser *)(list->data);
  if (parser->token[0] == OP_AND[0])
    my_rm_elem_in_list2_begin(&list);

  // last check redirection / ??
  if (list != NULL)
    {
      parser = (t_parser *)(list->data);
      if (parser->type == TOKEN_OPERATOR)
	{
	  if (my_get_char_pos(&OPS[2], parser->token[0]) != -1) /* pour bonus: utiliser is_operators */
	    return (my_puterr(ERROR_2), NULL);
	  else if (list->next != NULL)
	    {
	      parser = (t_parser *)(list->next->data);
	      if (my_get_char_pos(&OPS[2], parser->token[0]) != -1)
		return (my_puterr(ERROR_2), NULL);
	    }
	  parser = (t_parser *)(list->data);
	  if (!my_strcmp(parser->token, OP_PIPE))
	    return (my_puterr(ERROR_1), NULL);
	  /* printf("__ '%s'\n", parser->token); */
	}
      // check redirection without command
      if (list->next != NULL)
	{
	  parser = (t_parser *)(list->data);
	  if (((parser->type == TOKEN_COMMAND ||
		parser->type == TOKEN_OPTION) &&
	       (parser = (t_parser *)(list->next->data)) != NULL &&
	       parser->type == TOKEN_OPERATOR &&
	       my_get_char_pos(&OPS[2], parser->token[0]) != -1) &&
	      list->next->next == NULL)
	    return (my_puterr(ERROR_1), NULL);
	}
    }
  return (generate_commands_list(list));
}
