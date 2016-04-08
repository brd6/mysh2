/*
** exec_multi_pipes.c for exec_multi_pipes in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Apr  1 18:05:39 2016 Berdrigue BONGOLO BETO
** Last update Fri Apr  8 10:46:44 2016 Berdrigue BONGOLO BETO
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"

t_cmd		*loop_pipe(t_mysh *mysh, t_list *list, t_my_builtin *builtins)
{
  int		pipefd[2];
  pid_t		son_pid;
  int		fd_in;
  int		i;
  t_list	*tmp;
  t_cmd		*cmd;
  int		builtin_index;
  int		end_with_exit;

  fd_in = 0;
  i = 1;
  tmp = list;
  son_pid = -1;
  while (tmp != NULL)
    {
      cmd = ((t_cmd *)(tmp->data));
      /* printf("%s\n", cmd->options[0]); */
      if (pipe(pipefd) == -1)
      	return (my_puterr(ERR_PIPE), NULL);
      builtin_index = is_builins_cmd(cmd->command, builtins);
      end_with_exit = (tmp->next == NULL && !my_strcmp(cmd->command, "exit"));
      if ((son_pid = fork()) == -1)
	return (my_puterr(ERR_FORK), NULL);
      if (son_pid == 0)
      	{
	  close(pipefd[0]);
      	  dup2(fd_in, 0);
	  /* close(fd_in); */
      	  if (tmp->next != NULL)
	    {
	      dup2(pipefd[1], 1);
	      close(pipefd[1]);
	    }
      	  /* close(pipefd[0]); */
	  if ((builtin_index = is_builins_cmd(cmd->command, builtins)) != -1)
	    {
	      if (!(tmp->next == NULL && !my_strcmp(cmd->command, "exit")))
		builtins[builtin_index].func(mysh, cmd);
	      /* if (builtins[builtin_index].func(mysh, cmd) == EXIT_PROG) */
	      /* 	exit(2); */
	      exit(0);
	    }
	  else
	    son_process_action(mysh, cmd, builtins);
      	}
      else
      	{
      	  close(pipefd[1]);
      	  fd_in = pipefd[0];
      	  tmp = tmp->next;
      	}
    }
  father_process_action(son_pid);
  /* if (!my_strcmp(cmd->command, "exit") && */
  /*     (builtin_index = is_builins_cmd(cmd->command, builtins)) != -1) */
  /*   { */
  /*     printf("%d\n", end_with_exit); */
  /*     /\* int devNull = open("/dev/null", O_WRONLY); *\/ */
  /*     /\* dup2(devNull, 1); *\/ */
  /*     return (builtins[builtin_index].func(mysh, cmd)); */
  /*   } */
  return (cmd);
}

int		exec_multi_pipes(t_mysh *mysh,
				 t_cmd *cmd2,
				 t_my_builtin *builtins,
				 t_cmd **exit_cmd)
{
  t_cmd		*cmd;
  t_list	*list;

  if ((cmd2->line = my_str_replace("|", ";", cmd2->line, -1)) == NULL)
    return (GO_ON);
  if ((list = check_valid_line(cmd2->line)) == NULL)
    return (GO_ON);
  *exit_cmd = loop_pipe(mysh, list, builtins);;
  return (GO_ON);
}
