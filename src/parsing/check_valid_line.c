/*
** check_valid_line.c for check_valid_line in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Mar 21 01:17:35 2016 Berdrigue BONGOLO BETO
** Last update Thu Apr  7 15:52:28 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"
#include "parser.h"
#include "mysh.h"

int		check_token(t_list2 *list, char *str)
{
  if (check_str_command(list, str))
    return (TOKEN_COMMAND);
  if (check_str_option(list, str))
    return (TOKEN_OPTION);
  if (check_str_operator(list, str))
    return (TOKEN_OPERATOR);
  return (TOKEN_UNKNOWN);
}

char		*extract_command(char *line)
{
  char		*cmd;
  int		i;
  int		j;

  if ((cmd = malloc(sizeof(*cmd) * (my_strlen(line) + 1))) == NULL)
    exit_on_error(ERR_MALLOC);
  i = 0;
  j = 0;
  if (line[i] == '"' || line[i] == '\'')
    i++;
  else
    return (line);
  while (line[i] != '"' && line[i] != '\'')
    cmd[j++] = line[i++];
  cmd[j] = 0;
  return (cmd);
}

char		*get_str_cmd(char *str, int end_pos)
{
  char		*str_cmd;

  if ((str_cmd = malloc(sizeof(*str_cmd) * (my_strlen(str) + 1))) == NULL)
    exit_on_error("Malloc error\n");
  my_strncpy(str_cmd, str, end_pos);
  return (str_cmd);
}

/*
** Add a token to the list and check for useless ";"
** @list : a doubled linked list containing the tokens and their type
** @str : a token to add (operator or command)
** @type : token's type
*/
static void		add_to_cmd_list(t_list2 **list,
					char *str,
					int type)
{
  t_parser		*parser;
  t_parser		*parser_tmp;

  // check useless ;
  if (((*list != NULL &&
       (parser_tmp = ((t_parser *)((*list)->data))) &&
       type == TOKEN_OPERATOR && parser_tmp != NULL &&
       parser_tmp->token[0] == OP_AND[0]) || *list == NULL) &&
      str[0] == OP_AND[0])
    return;
  if ((parser = malloc(sizeof(*parser))) == NULL)
    exit_on_error(ERR_MALLOC);
  if (*list != NULL && (type == TOKEN_COMMAND || type == TOKEN_OPTION) &&
      (parser_tmp = ((t_parser *)((*list)->data))) &&
      (parser_tmp->type == TOKEN_COMMAND || parser_tmp->type == TOKEN_OPTION))
    parser->type = TOKEN_OPTION;
  else
    parser->type = type;
  parser->token = my_strdup(str);
  my_add_elem_in_list2_begin(list, parser);
}

t_list		*check_valid_line(char *line)
{
  int		i;
  char		**tab_line;
  t_list2	*list;
  int		ttype;
  int		j;
  char		*str_cmd;
  t_parser	*parser;

  i = 0;
  /* line = my_epur_str(line, " \t", 1); */
  /* line = my_epur_str(line, ";", 0); */
  /* line = my_epur_str(line, " \t", 1); */
  list = NULL;
  j = 0;
  str_cmd = NULL;
  while (line[i])
    {
      if (((j = check_next_operator(&line[i])) > -1 &&
	   ((ttype = TOKEN_OPERATOR))) ||
	  (j = check_next_command(&line[i])) > -1 &&
	  ((ttype = TOKEN_COMMAND)))
	str_cmd = get_str_cmd(&line[i], j);
      if (j == -2)
	return (NULL);
      if (j > 0)
	{
	  if (ttype == TOKEN_OPERATOR && !check_str_operator(list, str_cmd))
	    return (NULL);
	  add_to_cmd_list(&list, str_cmd, ttype);
	  i = i + j;
	}
      else
	i++;
    }
  /* free(line); */

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
  /* my_apply_on_rev_list2(list, print_list2_handler); */
  return (generate_commands_list(list));
}
