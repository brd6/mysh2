/*
** parser.h for parser in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Mar 27 00:31:47 2016 Berdrigue BONGOLO BETO
** Last update Sun Mar 27 04:01:28 2016 Berdrigue BONGOLO BETO
*/

#ifndef PARSER_H_
# define PARSER_H_

# define TOKEN_UNKNOWN -1
# define TOKEN_COMMAND 1
# define TOKEN_OPTION 2
# define TOKEN_OPERATOR 3

# define OP_PIPE "|"
# define OP_AND ";"
# define OP_R_REDIRECT ">"
# define OP_RR_REDIRECT ">>"
# define OP_L_REDIRECT "<"
# define OP_LL_REDIRECT "<<"

# define ERROR_1 "Invalid null command.\n"
# define ERROR_2 "Missing name for redirect.\n"

typedef struct	s_parser
{
  int		type;
  char		*token;
}		t_parser;

int		check_operator(t_list2 *list, char *str);
int		check_command(t_list2 *list, char *str);
int		check_option(t_list2 *list, char *str);
#endif /* !PARSER_H_ */
