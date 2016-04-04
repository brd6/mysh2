/*
** exec_simple_cmd.c for exec_simple_cmd in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Apr  1 18:08:23 2016 Berdrigue BONGOLO BETO
** Last update Tue Apr  5 00:14:10 2016 Berdrigue BONGOLO BETO
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int		execute_cmd_system(t_mysh *mysh,
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
  if (son_status == 512)
    return (EXIT_PROG);
  return (GO_ON);
}

int		exec_simple_cmd(t_mysh *mysh,
				t_cmd *cmd,
				t_my_builtin *builtins)
{
  // is_at_begin a check avant (redirection avant)
  int		builtin_index;

  /* printf("command:%s\n", cmd->command); */
  /* printf("command:%s %s\n", cmd->options[0], cmd->options[1]); */
  /* exec_cmd_system(); */
  /* if ((builtin_index = is_builins_cmd(cmd->command, builtins)) != -1) */
  /*   { */
  /*     return (builtins[builtin_index].func(mysh, cmd)); */
  /*   } */
  /* else */
  return (execute_cmd_system(mysh, cmd, builtins));
}
