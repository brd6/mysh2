/*
** generate_commands_list.c for generate_commands_list in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Apr  2 23:20:43 2016 Berdrigue BONGOLO BETO
** Last update Sun Apr  3 14:30:50 2016 Berdrigue BONGOLO BETO
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
      if (parser != NULL &&
	  parser->type == TOKEN_OPERATOR &&
	  parser->token[0] == OP_AND[0])
	break;
      if (parser->type == type ||
	  (ops != NULL &&
	   type == TOKEN_UNKNOWN &&
	   my_get_char_pos(ops, parser->token[0]) != -1))
	{
	  /* if (type == TOKEN_UNKNOWN) */
	  /* printf("! %s\n", ((t_parser *)(tmp->next->data))->token); */
	  i++;
	}
      tmp = tmp->prev;
    }
  /* if (type == TOKEN_UNKNOWN && ops[0] == '|') */
  /*   { */
  /*     printf("=> %s\n", parser->token); */
  /*     printf("=> %d\n", i); */
  /*   } */
  return ((type == TOKEN_OPTION) ? i + 1 : i);
}

static t_cmd	*alloc_cmd_list(t_list2 *parser_list)
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
	{
	  tmp = tmp->prev;
	  break;
	}
      if (parser->type == TOKEN_COMMAND)
	{
	  cmd->command = my_strdup(parser->token);
	  cmd->options[i++] = my_strdup(parser->token);
	}
      else if (parser->type == TOKEN_OPTION)
	cmd->options[i++] = my_strdup(parser->token);
      else if (parser->type == TOKEN_OPERATOR &&
      	       my_get_char_pos(&OPS[2], parser->token[0]) != -1)
      	{
	  cmd->redirect[j].type = my_strdup(parser->token);
	  parser = ((t_parser *)(tmp->prev->data));
      	  cmd->redirect[j].is_at_begin = (j == 0 && i == 0);
      	  cmd->redirect[j++].file = my_strdup(parser->token);
	  tmp = tmp->prev;
      	}
      tmp = tmp->prev;
    }
  cmd->options[i] = NULL;
  cmd->redirect[j].file = NULL;
  /* if (tmp != NULL && tmp->prev != NULL) */
  /*   tmp = tmp->prev; */

  return (tmp);
}

static t_list2	*goto_next_cmd_in_list(t_list2 *parser_list)
{
  t_list2	*tmp;
  t_parser	*parser;

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

static t_list2	*add_to_cmd_list(t_list2 *parser_list,
				 char *line,
				 t_list **list,
				 int i)
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
      parser_list = goto_next_cmd_in_list(parser_list);
      /* parser_list = parser_list->prev; */
    }
  else
    parser_list = fill_cmd_list(cmd, parser_list);

  /* // go to the next cmd (after a ";" operator) */
  /* if (parser_list != NULL && parser_list->prev != NULL) */
  /*   parser_list = parser_list->prev; */
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
    parser_tmp = add_to_cmd_list(parser_tmp, parser_tab[i++], &list, i);
  free(parser_tmp);
  my_free_wordtab(parser_tab);
  return (list);
}
