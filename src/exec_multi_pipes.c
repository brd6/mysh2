/*
** exec_multi_pipes.c for exec_multi_pipes in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Apr  1 18:05:39 2016 Berdrigue BONGOLO BETO
** Last update Wed Apr  6 18:32:28 2016 Berdrigue BONGOLO BETO
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int		loop_pipe(t_mysh *mysh, t_list *list, t_my_builtin *builtins)
{
  int		pipefd[2];
  pid_t		son_pid;
  int		fd_in;
  int		i;
  t_list	*tmp;
  t_cmd		*cmd;

  fd_in = 0;
  i = 1;
  tmp = list;
  while (tmp != NULL)
    {
      cmd = ((t_cmd *)(tmp->data));
      /* printf("%s\n", cmd->options[0]); */
      if (pipe(pipefd) == -1)
      	return (my_puterr(ERR_PIPE), 0);
      if ((son_pid = fork()) == -1)
      	return (my_puterr(ERR_FORK), 0);
      else if (son_pid == 0)
      	{
      	  dup2(fd_in, 0);
      	  if (tmp->next != NULL)
      	    dup2(pipefd[1], 1);
      	  close(pipefd[0]);
      	  son_process_action(mysh, cmd, builtins);
      	}
      else
      	{
      	  father_process_action(son_pid);
      	  close(pipefd[1]);
      	  fd_in = pipefd[0];
      	  tmp = tmp->next;
      	}
    }
}

int		exec_multi_pipes(t_mysh *mysh,
				 t_cmd *cmd2,
				 t_my_builtin *builtins)
{
  t_cmd		*cmd;
  t_list	*list;

  if ((cmd2->line = my_str_replace("|", ";", cmd2->line, -1)) == NULL)
    return (GO_ON);
  if ((list = check_valid_line(cmd2->line)) == NULL)
    return (GO_ON);
  loop_pipe(mysh, list, builtins);
  printf("ok\n");
  return (GO_ON);
}
