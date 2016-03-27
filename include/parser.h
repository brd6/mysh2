/*
** parser.h for parser in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Mar 27 00:31:47 2016 Berdrigue BONGOLO BETO
** Last update Sun Mar 27 17:48:34 2016 Berdrigue BONGOLO BETO
*/

#ifndef PARSER_H_
# define PARSER_H_

# define TOKEN_UNKNOWN -1
# define TOKEN_COMMAND 1
# define TOKEN_OPTION 2
# define TOKEN_OPERATOR 3

# define OPS "|;><"
# define OP_PIPE "|"
# define OP_AND ";"
# define OP_R_REDIRECT ">"
# define OP_RR_REDIRECT ">>"
# define OP_L_REDIRECT "<"
# define OP_LL_REDIRECT "<<"

# define ERROR_1 "Invalid null command.\n"
# define ERROR_2 "Missing name for redirect.\n"
# define ERROR_3 "Unmatched \".\n"

# include "mylist.h"

typedef struct	s_parser
{
  int		type;
  char		*token;
}		t_parser;

int		check_str_operator(t_list2 *list, char *str);
int		check_str_command(t_list2 *list, char *str);
int		check_str_option(t_list2 *list, char *str);

int		check_next_command(char *line);
int		check_next_operator(char *line);

/*
** Print errors
*/
void		print_error_unmatched(char c);

void		exit_on_error(char *msg);
#endif /* !PARSER_H_ */
