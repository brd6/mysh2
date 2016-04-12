/*
** parser_checker2.c for parser_checker2 in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Mar 27 16:21:07 2016 Berdrigue BONGOLO BETO
** Last update Tue Apr 12 15:50:54 2016 Berdrigue BONGOLO BETO
*/

#include "my.h"
#include "parser.h"

static void	set_nb_quote(int *end_char_cp, char c)
{
  if (c == '"' && end_char_cp[1] % 2 == 0)
    end_char_cp[0]++;
  else if (c == '\'' && end_char_cp[0] % 2 == 0)
    end_char_cp[1]++;
}

/*
** check if there are an operator in the next line.
** return : the end position of operator
*/
int		check_next_operator(char *line)
{
  if (line[0] != 0 && my_get_char_pos(OPS, line[0]) != -1)
    {
      if (my_get_char_pos(&OPS[2], line[1]) != -1 && line[0] == line[1])
	return (2);
      return (1);
    }
  return (-1);
}

static void	init_check_next_command(char *end_char,
					char *line,
					int *i,
					int *bak_i)
{
  *end_char = (line[0] == '"' || line[0] == '\'') ? line[0] : ' ';
  *i = 0;
  *bak_i = 0;
}

static int	check_cmd_end(char end_char, char *line, int *i)
{
  if ((end_char == ' ' && my_get_char_pos(OPS, line[*i + 1]) != -1) ||
      ((line[*i] == end_char || (line[*i] == '\t' && end_char == ' ')) &&
       (line[*i + 1] == 0 || (line[*i + 1] != end_char ||
			      line[*i + 1] != '\t'))))
    {
      if (end_char != ' ' ||
	  ((line[*i] != ' ' && line[*i] != '\t') &&
	   my_get_char_pos(OPS, line[*i]) == -1))
	*i = *i + 1;
      return (1);
    }
  return (0);
}

/*
** check if there are a command in the next line.
** return : the end position of command
*/
int		check_next_command(char *line)
{
  char		end_char;
  int		i;
  int		end_cp[2];
  int		bak_i;

  init_check_next_command(&end_char, line, &i, &bak_i);
  if (end_char == ' ' && (line[0] == ' ' || line[0] == '\t'))
    return (-1);
  end_cp[0] = (end_cp[1] = 0);
  if (end_char != ' ' && (line[0] == end_char || line[0] == '\t'))
    set_nb_quote(end_cp, line[i++]);
  while (line[i])
    {
      set_nb_quote(end_cp, line[i]);
      if (check_cmd_end(end_char, line, &i))
	break;
      if ((line[i] == '"' || line[i] == '\'') &&
	  (end_cp[0] % 2 != 0 || end_cp[1] % 2 != 0))
	bak_i = i;
      i++;
    }
  if (end_cp[0] % 2 != 0 || end_cp[1] % 2 != 0)
    return (print_error_unmatched(line[bak_i]), -2);
  return (i);
}
