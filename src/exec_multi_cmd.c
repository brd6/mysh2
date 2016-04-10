/*
** exec_multi_cmd.c for exec_multi_cmd.c in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Apr  1 16:43:46 2016 Berdrigue BONGOLO BETO
** Last update Sun Apr 10 16:19:24 2016 Berdrigue BONGOLO BETO
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int		exec_cmd(t_mysh *mysh,
			 t_cmd *cmd,
			 t_my_builtin *builtins,
			 t_cmd **exit_cmd)
{
  if (cmd->is_pipe_line)
    return (exec_multi_pipes(mysh, cmd, builtins, exit_cmd));
  else
    return (exec_simple_cmd(mysh, cmd, builtins));
  return (GO_ON);
}

int		exec_multi_cmd(t_mysh *mysh,
			       t_list *cmd,
			       t_my_builtin *builtins)
{
  t_list	*tmp;
  t_cmd		*exit_cmd;;
  int		builtin_index;

  tmp = cmd;
  exit_cmd = ((t_cmd *)(tmp->data));
  while (tmp != NULL)
    {
      if (!((t_cmd *)(tmp->data))->is_pipe_line &&
	  !my_strcmp(((t_cmd *)(tmp->data))->command, "exit"))
	exit_cmd = ((t_cmd *)(tmp->data));
      exec_cmd(mysh, tmp->data, builtins, &exit_cmd);
      tmp = tmp->next;
    }
  if (exit_cmd != NULL && !exit_cmd->is_pipe_line &&
      !my_strcmp(exit_cmd->command, "exit") &&
      (builtin_index = is_builins_cmd(exit_cmd->command, builtins)) != -1)
    return (builtins[builtin_index].func(mysh, exit_cmd));
  return (GO_ON);
}
