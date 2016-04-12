/*
** exec_multi_pipes.c for exec_multi_pipes in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Apr  1 18:05:39 2016 Berdrigue BONGOLO BETO
** Last update Tue Apr 12 15:58:46 2016 Berdrigue BONGOLO BETO
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"

static void	init_loop_pipe(int *fd_in,
			       t_list **tmp,
			       t_list *list,
			       int *son_pid)
{
  *fd_in = 0;
  *son_pid = -1;
  *tmp = list;
}

static void	pipe_exec(t_cmd *cmd,
			  t_my_builtin *builtins,
			  t_mysh *mysh,
			  t_list *tmp)
{
  int		builtin_index;

  if ((builtin_index = is_builins_cmd(cmd->command, builtins)) != -1)
    {
      if (!(tmp->next == NULL && !my_strcmp(cmd->command, "exit")))
	builtins[builtin_index].func(mysh, cmd);
      exit(0);
    }
  else
    son_process_action(mysh, cmd);
}

static void	pipe_son_dup(int *pipefd, int *fd_in, t_list **tmp, int flag)
{
  if (!flag)
    {
      close(pipefd[0]);
      dup2(*fd_in, 0);
      if ((*tmp)->next != NULL)
	{
	  dup2(pipefd[1], 1);
	  close(pipefd[1]);
	}
    }
  else
    {
      close(pipefd[1]);
      *fd_in = pipefd[0];
      *tmp = (*tmp)->next;
    }
}

static t_cmd	*loop_pipe(t_mysh *mysh, t_list *list, t_my_builtin *builtins)
{
  int		pipefd[2];
  pid_t		son_pid;
  int		fd_in;
  t_list	*tmp;
  t_cmd		*cmd;

  init_loop_pipe(&fd_in, &tmp, list, &son_pid);
  while (tmp != NULL)
    {
      cmd = ((t_cmd *)(tmp->data));
      if (pipe(pipefd) == -1)
      	return (my_puterr(ERR_PIPE), NULL);
      if ((son_pid = fork()) == -1)
	return (my_puterr(ERR_FORK), NULL);
      if (son_pid == 0)
      	{
	  pipe_son_dup(pipefd, &fd_in, &tmp, 0);
	  pipe_exec(cmd, builtins, mysh, tmp);
      	}
      else
	pipe_son_dup(pipefd, &fd_in, &tmp, 1);
    }
  father_process_action(son_pid);
  return (cmd);
}

int		exec_multi_pipes(t_mysh *mysh,
				 t_cmd *cmd2,
				 t_my_builtin *builtins,
				 t_cmd **exit_cmd)
{
  t_list	*list;

  if ((cmd2->line = my_str_replace("|", ";", cmd2->line, -1)) == NULL)
    return (GO_ON);
  if ((list = check_valid_line(cmd2->line)) == NULL)
    return (GO_ON);
  *exit_cmd = loop_pipe(mysh, list, builtins);;
  return (GO_ON);
}
