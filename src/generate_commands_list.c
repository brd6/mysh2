/*
** generate_commands_list.c for generate_commands_list in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Apr  2 23:20:43 2016 Berdrigue BONGOLO BETO
** Last update Sun Apr  3 02:58:59 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "parser.h"

/*
** Count a type of command in the list
** @parser_list : a doubled linked list containing the tokens and their type
** return : number of type (+ 1 for option type)
*/
static int	count_command_type(t_list2 *parser_list,
				   int type,
				   char *ops)
{
  int		i;
  t_list2	*tmp;
  t_parser	*parser;

  i = 0;
  tmp = parser_list;
  while (tmp != NULL)
    {
      parser = ((t_parser *)(tmp->data));
      if (parser->type == TOKEN_OPERATOR && parser->token[0] == OP_AND[0])
	break;
      if (parser->type == type ||
	  (ops != NULL &&
	   my_get_char_pos(ops, parser->token[0]) != -1))
	i++;
      tmp = tmp->prev;
    }
  return ((type == TOKEN_OPTION) ? i + 1 : i);
}

static t_cmd	*alloc_cmd_list(t_list2 *parser_list)
{
  t_cmd		*cmd;

  if ((cmd = malloc(sizeof(*cmd))) == NULL)
    return (NULL);
  if ((cmd->options = malloc(count_command_type(parser_list, TOKEN_OPTION, NULL) + 1)) == NULL)
    return (NULL);
  if ((cmd->redirect = malloc(count_command_type(parser_list, TOKEN_UNKNOWN, &OPS[2]) + 1)) == NULL)
    return (NULL);
  return (cmd);
}

static t_list2	*fill_cmd_list(t_cmd *cmd, t_list2 *parser_list)
{
  t_list2	*tmp;
  t_parser	*parser;
  int		i;
  int		j;

  tmp = parser_list;
  i = 0;
  j = 0;
  cmd->is_pipe_line = 0;
  cmd->command = NULL;
  while (tmp != NULL)
    {
      parser = ((t_parser *)(tmp->data));
      if (parser->type == TOKEN_OPERATOR && parser->token[0] == OP_AND[0])
	break;
      if (parser->type == TOKEN_COMMAND)
	cmd->command = my_strdup(parser->token);
      else if (parser->type == TOKEN_OPTION)
	{
	  cmd->options[i++] = my_strdup(parser->token);
	}
      else if (parser->type == TOKEN_OPERATOR &&
      	       my_get_char_pos(&OPS[2], parser->token[0]) != -1)
      	{
	  cmd->redirect[j].type = my_strdup(parser->token);
	  parser = ((t_parser *)(tmp->prev->data));
      	  cmd->redirect[j++].file = my_strdup(parser->token);
	  tmp = tmp->prev;
      	}
      tmp = tmp->prev;
    }
  cmd->options[i] = NULL;
  cmd->redirect[j].file = NULL;
  return (tmp);
}

static t_list2	*add_to_cmd_list(t_list2 *parser_list,
				 char *line,
				 t_list **list)
{
  t_cmd		*cmd;

  if (line == NULL)
    return (NULL);
  if ((cmd = alloc_cmd_list(parser_list)) == NULL)
    return (NULL);
  cmd->line = my_strdup(line);
  if (count_command_type(parser_list, TOKEN_UNKNOWN, OP_PIPE) > 0)
    {
      cmd->is_pipe_line = 1;
      cmd->options = NULL;
      parser_list = parser_list->prev;
    }
  else
    parser_list = fill_cmd_list(cmd, parser_list);

  // add
  my_add_elem_in_list_end(list, cmd);
  return (parser_list);
}

t_list		*generate_commands_list(t_list2 *parser_list)
{
  t_list	*list;
  t_list2	*parser_tmp;
  char		*parser_str;
  char		**parser_tab;
  int		i;

  list = NULL;
  if ((parser_str = parser_list_to_str(parser_list)) == NULL ||
      (parser_tab = my_str_split(parser_str, ";")) == NULL)
    return (NULL);
  parser_tmp = parser_list;
  while (parser_tmp->next != NULL)
    parser_tmp = parser_tmp->next;
  i = 0;
  while (parser_tmp != NULL)
    parser_tmp = add_to_cmd_list(parser_tmp, parser_tab[i++], &list);
  free(parser_tmp);
  my_free_wordtab(parser_tab);
  return (list);
}
