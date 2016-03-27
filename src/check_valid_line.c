/*
** check_valid_line.c for check_valid_line in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Mar 21 01:17:35 2016 Berdrigue BONGOLO BETO
** Last update Sun Mar 27 18:07:25 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"
#include "parser.h"

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
    exit_on_error("Malloc error\n");
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


void		show_list2(t_list2 *begin)
{
  t_list2	*curr;
  t_parser	*parser;

  curr = begin;
  while (curr)
    {
      parser = ((t_parser *)(curr->data));
      printf("%s (%d)\n", parser->token, parser->type);
      curr = curr->next;
    }
  my_putstr("\n");
}

void		add_to_cmd_list(t_list2 **list,
				char *str,
				int end_pos,
				int type)
{
  int		i;
  char		*str_cmd;
  t_parser	*parser;

  if ((str_cmd = malloc(sizeof(*str_cmd) * (my_strlen(str) + 1))) == NULL)
    exit_on_error("Malloc error\n");
  my_strncpy(str_cmd, str, end_pos);
  if ((parser = malloc(sizeof(*parser))) == NULL)
    exit_on_error("Malloc error\n");
  parser->type = type;
  parser->token = my_strdup(str_cmd);
  my_add_elem_in_list2_end(list, parser);
  show_list2(*list);
}

static int	skip_char(char *str, char *s)
{
  int		i;

  i = 0;
  while (my_get_char_pos(s, str[i]) != -1)
    i++;
  return (i);
}

int		check_valid_line(char *line)
{
  int		i;
  char		**tab_line;
  t_list2	*list;
  int		token_type;
  int		j;

  i = 0;
  line = my_epur_str(line, " \t", 1);
  line = my_epur_str(line, ";", 0);
  line = my_epur_str(line, " \t", 1);
  /* printf("'%s' => '%s'\n", line, extract_command(line)); */
  list = NULL;
  j = 0;
  while (line[i])
    {
      if ((j = check_next_operator(&line[i])) > -1)
	{
	  /* printf("operator: '%s' (%d)\n", &line[i], i + j); */
	  add_to_cmd_list(&list, &line[i], j, TOKEN_OPERATOR);
	}
      else if ((j = check_next_command(&line[i])) > -1)
	{
	  /* printf("command: '%s' (%d)\n", &line[i], i + j); */
	  add_to_cmd_list(&list, &line[i], j, TOKEN_COMMAND);
	}
      /* printf("=> %d\n", (j = check_next_operator(&line[i]))); */
      /* printf("=> %d\n", (j = check_next_command(&line[i])) + i); */
      if (j == -2)
	break;
      if (j > 0)
	i = i + j;
      else
	i++;
    }
  show_list2(list);
  free(line);
  return (0);
}
