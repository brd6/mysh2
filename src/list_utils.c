/*
** list_utils.c for list_utils in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Mar 28 19:37:16 2016 Berdrigue BONGOLO BETO
** Last update Sun Apr 10 14:42:16 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "my_printf.h"
#include "parser.h"

void		print_list2_handler(void *data)
{
  t_parser	*parser;

  if (data == NULL)
    return;
  parser = ((t_parser *)(data));
  my_printf("'%s' (%d)\n", parser->token, parser->type);
}

int		find_key(char *data, char *data_ref)
{
  return ((my_strstr(data, data_ref) != NULL) ? 0 : 1);
}

t_cmd		*alloc_cmd_list(t_list2 *parser_list)
{
  t_cmd		*cmd;
  int		options_size;
  int		redi_size;

  if ((cmd = malloc(sizeof(*cmd))) == NULL)
    return (NULL);
  options_size = count_command_type(parser_list, TOKEN_OPTION, NULL) + 1;
  if ((cmd->options = malloc(sizeof(*(cmd->options)) * options_size)) == NULL)
    return (NULL);
  redi_size = count_command_type(parser_list, TOKEN_UNKNOWN, &OPS[2]) + 1;
  if ((cmd->redirect = malloc(sizeof(*(cmd->redirect)) * (redi_size))) == NULL)
    return (NULL);
  return (cmd);
}
