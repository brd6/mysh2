/*
** exec_simple_cmd.c for exec_simple_cmd in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Apr  1 18:08:23 2016 Berdrigue BONGOLO BETO
** Last update Sun Apr 10 16:37:34 2016 Berdrigue BONGOLO BETO
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"

static int	execute_cmd_system(t_mysh *mysh,
				   t_cmd *cmd,
				   t_my_builtin *builtins)
{
  pid_t		son_pid;
  int		son_status;

  if ((son_pid = fork()) == -1)
    my_puterr(ERR_FORK);
  else if (son_pid == 0)
    son_process_action(mysh, cmd, builtins);
  else
    son_status = father_process_action(son_pid);
  return (GO_ON);
}

int		exec_simple_cmd(t_mysh *mysh,
				t_cmd *cmd,
				t_my_builtin *builtins)
{
  int		builtin_index;

  if (my_strcmp(cmd->command, "exit") &&
      (builtin_index = is_builins_cmd(cmd->command, builtins)) != -1)
    return (builtins[builtin_index].func(mysh, cmd));
  else if (my_strcmp(cmd->command, "exit") &&
	   execute_cmd_system(mysh, cmd, builtins) == EXIT_PROG)
    return (EXIT_PROG);
  return (GO_ON);
}
