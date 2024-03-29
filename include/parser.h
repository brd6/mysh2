/*
** parser.h for parser in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Mar 27 00:31:47 2016 Berdrigue BONGOLO BETO
** Last update Sun Apr 10 16:16:22 2016 Berdrigue BONGOLO BETO
*/

#ifndef PARSER_H_
# define PARSER_H_

# define TOKEN_UNKNOWN -1
# define TOKEN_COMMAND 1
# define TOKEN_OPTION 2
# define TOKEN_OPERATOR 3
# define OPS ";|><"
# define OP_PIPE "|"
# define OP_AND ";"
# define OP_R_REDIRECT ">"
# define OP_RR_REDIRECT ">>"
# define OP_L_REDIRECT "<"
# define OP_LL_REDIRECT "<<"
# define ERROR_1 "Invalid null command.\n"
# define ERROR_2 "Missing name for redirect.\n"
# define ERROR_3 "Unmatched \".\n"
# define ERROR_4 "Ambiguous output redirect.\n"
# define ERROR_5 "Ambiguous input redirect.\n"

# include "mylist.h"

typedef struct	s_parser
{
  int		type;
  char		*token;
}		t_parser;

typedef struct	s_redirect
{
  char		*file;
  char		*type;
  int		is_at_begin;
}		t_redirect;

typedef struct	s_cmd
{
  char		*line;
  char		*command;
  char		**options;
  t_redirect	*redirect;
  int		is_pipe_line;
}		t_cmd;

int		check_str_operator(t_list2 *list, char *str);

int		check_next_command(char *line);
int		check_next_operator(char *line);

t_list		*generate_commands_list(t_list2 *parser);
char		*parser_list_to_str(t_list2 *list);
t_list2		*parsing_line(char *line);
int		generate_cmd_check_ambiguous_redi(int j,
						  t_cmd **cmd,
						  t_list **list,
						  int *is_redir_err);
void		generate_cmd_token_command(t_parser *parser,
					   t_cmd **cmd,
					   int *i);
char		*extract_command(char *line);
void		generate_cmd_token_operator(t_list2 **tmp,
					    t_cmd **cmd,
					    int i,
					    int *j);
t_cmd		*alloc_cmd_list(t_list2 *parser_list);
int		count_command_type(t_list2 *parser_list,
				   int type,
				   char *ops);
t_list2		*goto_next_cmd_in_list(t_list2 *parser_list);

/*
** Print errors
*/
void		print_error_unmatched(char c);

void		exit_on_error(char *msg);

void		print_list2_handler(void *data);
#endif /* !PARSER_H_ */
