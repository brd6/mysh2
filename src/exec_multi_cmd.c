/*
** exec_multi_cmd.c for exec_multi_cmd.c in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Apr  1 16:43:46 2016 Berdrigue BONGOLO BETO
** Last update Sun Apr  3 03:59:51 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int		exec_cmd(t_mysh *mysh, t_cmd *cmd, t_my_builtin *builtins)
{
  if (cmd->is_pipe_line)
    {
      my_printf("Pipes : %s\n", cmd->line);
      exec_multi_pipes();
    }
  else
    {
      my_printf("Simple : %s\n", cmd->line);
      exec_simple_cmd(mysh, cmd, builtins);
    }
  return (GO_ON);
}

int		exec_multi_cmd(t_mysh *mysh,
			       t_list *cmd,
			       t_my_builtin *builtins)
{
  t_list	*tmp;

  tmp = cmd;
  while (tmp != NULL)
    {
      if (exec_cmd(mysh, tmp->data, builtins) == EXIT_PROG)
	return (EXIT_PROG);
      tmp = tmp->next;
    }
}
