/*
** fork_action.c for fork_action in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Apr  3 15:04:05 2016 Berdrigue BONGOLO BETO
** Last update Thu Apr  7 19:37:23 2016 Berdrigue BONGOLO BETO
*/

/* #include <signal.h> */
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"

void		son_process_action(t_mysh *mysh, t_cmd *cmd, t_my_builtin *builtins)
{
  int		res;
  char		**env;
  char		*bin;
  int		builtin_index;

  if (((env = env_list_to_array(mysh->my_env)) == NULL))
    {
      free(env);
      free(bin);
      exit(1);
    }
  if (!redirect_cmd(cmd))
    exit(1);
  /* if (!my_strcmp(cmd->command, "exit") || !my_strcmp(cmd->command, "cd")) */
  /*   exit(1); */
  if (/* (builtin_index = is_builins_cmd(cmd->command, builtins)) != -1 */ 0)
    {
      builtins[builtin_index].func(mysh, cmd);
      /* if (builtins[builtin_index].func(mysh, cmd) == EXIT_PROG) */
      /* 	exit(2); */
      exit(0);
    }
  else
    {
      if ((bin = get_bin_path(cmd->command, key_to_value(mysh->my_env, "PATH"))) == NULL ||
	  !check_bin_permission(bin))
	exit(1);
      if ((res = execve(bin, cmd->options, env)) == -1)
	my_puterr(ERR_EXECVE);
    }
}

int		father_process_action(int son_pid)
{
  int		son_status;

  while (wait(&son_status) != son_pid);
  if (WIFSIGNALED(son_status) && WTERMSIG(son_status) == SIGSEGV)
    my_puterr(ERR_SEGMENTATION_FAULT);
  else if (WIFSIGNALED(son_status) && WTERMSIG(son_status) == SIGFPE)
    my_puterr(ERR_FLOATING_PTS_EXCP);
  /* else if (WIFEXITED(son_status)) */
  /*   my_putstr("Terminaison normal !\n"); */
  return (son_status);
}
