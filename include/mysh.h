/*
** mysh.h for mysh in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Mar 20 21:55:09 2016 Berdrigue BONGOLO BETO
** Last update Mon Apr  4 02:14:44 2016 Berdrigue BONGOLO BETO
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
# define ERR_MALLOC "Malloc error\n"
# define ERR_FORK "Error : unable to create a new process\n"
# define ERR_COMMAND_NOT_FOUND ": command not found.\n"
# define ERR_PERMISSION_DENIED ": Permission denied\n"
# define ERR_EXECVE "Execve: an error has occurred\n"
# define ERR_SEGMENTATION_FAULT "Segmentation Fault\n"
# define ERR_FLOATING_PTS_EXCP "Floating point exception\n"
# define ERR_ENV_PATH "There aren't PATH in the env variable\n"
# define EXIT_MSG "exit\n"
# define ERR_OPEN_FILE "Unable to open file\n"
# define ERR_DUP2 "dup2 error\n"
# define ERR_PIPE "pipe error\n"
# define FLG_FILE_PERM (S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR)
# define FLG_FILE_CWRITE (O_WRONLY | O_TRUNC | O_CREAT)
# define FLG_FILE_CWRITE2 (O_WRONLY | O_APPEND | O_CREAT)

# include "mylist.h"
# include "parser.h"

typedef struct	s_mysh
{
  t_list	*my_env;
  int		exit_code;
}		t_mysh;

typedef struct	s_my_builtin
{
  char		*name;
  int		(*func)(t_mysh *mysh, t_cmd *cmd);
}		t_my_builtin;

extern char	*g_prompt;

void		free_mysh(t_mysh *mysh);
void		sig_handler_sigint(int code);
void		sig_handler_heredoc(int code);
int		check_null_line(char *line);
t_list		*check_valid_line(char *line);
char		*epur_str(char *str, char *to_remove, int replace_with_space);
int		is_space_str(char *str);
char		*concat_two_str(char *str1, char *str2, char *c);

/*
** Env
*/
int		env_key_exist(t_list *my_env, char *key);
char		*key_to_value(t_list *env, char *key);
char		**env_list_to_array(t_list *my_env);

void		show_prompt(t_mysh *mysh);

/*
** Exec
*/
int		check_bin_permission(char *bin);
int		father_process_action(int son_pid);
void		son_process_action(char *bin, char **env, t_cmd *cmd);
char		*get_bin_path(char *bin, char *str_path);
struct stat	my_stat(char *file);
int		redirect_right(char *type, char *filename);
int		redirect_left(char *type, char *filename);
int		redirect_cmd(t_cmd *cmd);
t_list		*my_heredoc(char *eof);
int		exec_multi_cmd(t_mysh *mysh,
			       t_list *cmd,
			       t_my_builtin *builtins);
int		exec_simple_cmd(t_mysh *mysh,
				t_cmd *cmd,
				t_my_builtin *builtins);
int		exec_multi_pipes(t_mysh *mysh,
				 t_cmd *cmd,
				 t_my_builtin *builtins);


/*
** builtin utils
*/
void		init_builtins(t_my_builtin *builtins);
int		is_builins_cmd(char *cmd, t_my_builtin *builtins);

/*
** builtins
*/
int		builtin_exit(t_mysh *mysh, t_cmd *cmd);

#endif /* !MYSH_H_ */
