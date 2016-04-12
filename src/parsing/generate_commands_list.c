/*
** generate_commands_list.c for generate_commands_list in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Apr  2 23:20:43 2016 Berdrigue BONGOLO BETO
** Last update Tue Apr 12 15:52:17 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "parser.h"
#include "mysh.h"

static void	init_fill_cmd_list(int *i, int *j, t_cmd *cmd)
{
  *i = 0;
  *j = 0;
  cmd->is_pipe_line = 0;
  cmd->command = NULL;
}

static int	fill_cmd_list_stop_cond(t_parser *parser, t_list2 **tmp)
{
  if (parser->type == TOKEN_OPERATOR && parser->token[0] == OP_AND[0])
    {
      *tmp = (*tmp)->prev;
      return (1);
    }
  return (0);
}

/*
** Fill the list of command for execution and
** check also for ambigous redirection
** @cmd : current cmd info
** @parser_list : list of others cmd
** @list : final cmd simple list
** @is_redir_err : for redirection error
** return : double linked list representative list of commands to execute
*/
static t_list2	*fill_cmd_list(t_cmd *cmd,
			       t_list2 *parser_list,
			       t_list **list,
			       int *is_redir_err)
{
  t_list2	*tmp;
  t_parser	*parser;
  int		i;
  int		j;

  tmp = parser_list;
  init_fill_cmd_list(&i, &j, cmd);
  while (tmp != NULL)
    {
      parser = ((t_parser *)(tmp->data));
      if (fill_cmd_list_stop_cond(parser, &tmp))
  	break;
      if (parser->type == TOKEN_COMMAND)
	generate_cmd_token_command(parser, &cmd, &i);
      else if (parser->type == TOKEN_OPTION)
	cmd->options[i++] = my_strdup(parser->token);
      else if (parser->type == TOKEN_OPERATOR &&
      	       my_get_char_pos(&OPS[2], parser->token[0]) != -1)
	generate_cmd_token_operator(&tmp, &cmd, i, &j);
      tmp = tmp->prev;
    }
  cmd->options[i] = NULL;
  if (!generate_cmd_check_ambiguous_redi(j, &cmd, list, is_redir_err))
    return (NULL);
  return (tmp);
}

static t_list2	*add_to_cmd_list(t_list2 *parser_list,
				 char *line,
				 t_list **list)
{
  t_cmd		*cmd;
  int		is_redir_err;

  if (line == NULL)
    return (NULL);
  if ((cmd = alloc_cmd_list(parser_list)) == NULL)
    return (NULL);
  cmd->line = my_strdup(line);
  is_redir_err = 0;
  if (count_command_type(parser_list, TOKEN_UNKNOWN, OP_PIPE) > 0)
    {
      cmd->is_pipe_line = 1;
      cmd->options = NULL;
      cmd->command = NULL;
      parser_list = goto_next_cmd_in_list(parser_list);
    }
  else
    parser_list = fill_cmd_list(cmd, parser_list, list, &is_redir_err);
  if (is_redir_err)
    return (NULL);
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
