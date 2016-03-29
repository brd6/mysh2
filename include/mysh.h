/*
** mysh.h for mysh in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Mar 20 21:55:09 2016 Berdrigue BONGOLO BETO
** Last update Tue Mar 29 11:47:36 2016 Berdrigue BONGOLO BETO
*/

#ifndef MYSH_H_
# define MYSH_H_

# define GO_ON 1
# define EXIT_PROG 42
# define WHITE	"\033[0m"
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[0;34m"
# define BBLUE2	"\033[0;36m"
# define GRAY	"\033[0;37m"
# define BOLD	"\033[1m"
# define BWHITE	"\033[1;0m"
# define BRED	"\033[1;31m"
# define BGREEN	"\033[1;32m"
# define BBLUE	"\033[1;34m"
# define BCYAN	"\033[1;36m"

# include "mylist.h"

typedef struct	s_mysh
{
  t_list	*my_env;
  int		exit_code;
}		t_mysh;

typedef struct	s_my_builtin
{
  char		*name;
  int		(*func)(t_mysh *mysh, char **args);
}		t_my_builtin;

extern char	*g_prompt;

void		free_mysh(t_mysh *mysh);
void		sig_handler_sigint(int code);
int		check_null_line(char *line);
int		check_valid_line(char *line);
char		*epur_str(char *str, char *to_remove, int replace_with_space);
int		is_space_str(char *str);

int		env_key_exist(t_list *my_env, char *key);
char		*key_to_value(t_list *env, char *key);
void		show_prompt(t_mysh *mysh);

/*
** builtins
*/
void		init_builtins(t_my_builtin *builtins);
#endif /* !MYSH_H_ */
