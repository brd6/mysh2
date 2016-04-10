/*
** generate_commands_list_utils2.c for generate_commands_list_utils2 in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Apr 10 14:45:46 2016 Berdrigue BONGOLO BETO
** Last update Sun Apr 10 14:46:44 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "parser.h"

t_list2		*goto_next_cmd_in_list(t_list2 *parser_list)
{
  t_list2	*tmp;
  t_parser	*parser;

  tmp = parser_list;
  while (tmp != NULL)
    {
      parser = ((t_parser *)(tmp->data));
      if (parser->type == TOKEN_OPERATOR && parser->token[0] == OP_AND[0])
	{
	  tmp = tmp->prev;
	  break;
	}
      tmp = tmp->prev;
    }
  return (tmp);
}
