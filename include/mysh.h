/*
** mysh.h for mysh in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Mar 20 21:55:09 2016 Berdrigue BONGOLO BETO
** Last update Wed Apr 13 11:39:37 2016 Berdrigue BONGOLO BETO
*/

#ifndef MYSH_H_
# define MYSH_H_

# define GO_ON 1
# define EXIT_PROG 42
# define ERR_MALLOC "Malloc error\n"
# define ERR_FORK "Error : unable to create a new process\n"
# define ERR_COMMAND_NOT_FOUND ": command not found.\n"
# define ERR_PERMISSION_DENIED ": Permission denied\n"
# define ERR_EXECVE "Execve: an error has occurred\n"
# define ERR_SEGMENTATION_FAULT "Segmentation Fault\n"
# define ERR_FLOATING_PTS_EXCP "Floating point exception\n"
# define ERR_ENV_PATH "There aren't PATH in the env variable\n"
# define ERR_OPEN_FILE "Unable to open file\n"
# define ERR_DUP2 "dup2 error\n"
# define ERR_PIPE "pipe error\n"
# define ERR_HEREDOC "heredoc error\n"
# define ERR_FILE_NOEXIST "'%s': No such file or folder type.\n"
# define ERR_FILE_NOACCESS "%s: Unauthorized access\n"
# define ERR_NODIRECTORY "%s: Not a directory\n"
# define ERR_GETWCD "getcwd error\n"
# define ERR_SETENV_VARNAME1 "setenv: Variable name must begin with a letter.\n"
# define ERR_SETENV_VARNAME2 "setenv: Variable name must contain alphanumeric characters.\n"
# define ERR_SETENV_MALLOC "setenv: Unable to set a new variable to the env\n"
# define ERR_EXIT_EXPR_SYNTAX "exit: Expression Syntax.\n"
# define FLG_FILE_PERM (S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR)
# define FLG_FILE_CWRITE (O_WRONLY | O_TRUNC | O_CREAT)
# define FLG_FILE_CWRITE2 (O_WRONLY | O_APPEND | O_CREAT)
# define HEREDOC_TMP1 "/tmp/.mysh_heredoc_%pid%"
# define HEREDOC_TMP2 ".mysh_heredoc_%pid%"
# define EXIT_MSG "exit\n"
# define MAX_CMD_LEN 1024
# define PROMPT "$> "

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

void		free_mysh(t_mysh *mysh);
void		sig_handler_sigint(int code);
void		sig_handler_heredoc(int code);
int		check_null_line(char *line);
t_list		*check_valid_line(char *line);
char		*epur_str(char *str, char *to_remove, int replace_with_space);
int		is_space_str(char *str);
char		*concat_two_str(char *str1, char *str2, char *c);
int		find_key(char *data, char *data_ref);
int		directory_exist(char *dirr);

/*
** Env
*/
int		env_key_exist(t_list *my_env, char *key);
char		*key_to_value(t_list *env, char *key);
int		env_key_exist_v(t_list *my_env, char *key);
char		**env_list_to_array(t_list *my_env);

/*
** Exec
*/
int		check_bin_permission(char *bin);
int		father_process_action(int son_pid);
void		son_process_action(t_mysh *mysh,
				   t_cmd *cmd);
char		*get_bin_path(char *bin, char *str_path);
struct stat	my_stat(char *file);
int		redirect_right(char *type, char *filename);
int		redirect_left(char *type, char *filename);
int		redirect_cmd(t_cmd *cmd);
t_list		*my_heredoc(char *eof);
char		*filewrite_heredoc(t_list *list);
int		exec_multi_cmd(t_mysh *mysh,
			       t_list *cmd,
			       t_my_builtin *builtins);
int		exec_simple_cmd(t_mysh *mysh,
				t_cmd *cmd,
				t_my_builtin *builtins);
int		exec_multi_pipes(t_mysh *mysh,
				 t_cmd *cmd2,
				 t_my_builtin *builtins,
				 t_cmd **exit_cmd);

/*
** builtin utils
*/
void		init_builtins(t_my_builtin *builtins);
int		is_builins_cmd(char *cmd, t_my_builtin *builtins);

/*
** builtins
*/
int		builtin_exit(t_mysh *mysh, t_cmd *cmd);
int		builtin_cd(t_mysh *mysh, t_cmd *cmd);
int		builtin_env(t_mysh *mysh, t_cmd *cmd);
int		builtin_setenv(t_mysh *mysh, t_cmd *cmd);
int		builtin_unsetenv(t_mysh *mysh, t_cmd *cmd);
#endif /* !MYSH_H_ */
