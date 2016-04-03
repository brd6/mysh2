/*
** fork_action.c for fork_action in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Apr  3 15:04:05 2016 Berdrigue BONGOLO BETO
** Last update Sun Apr  3 15:16:19 2016 Berdrigue BONGOLO BETO
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"

void		son_process_action(char *bin, char **env, char **args)
{
  int		res;

  if (!check_bin_permission(bin))
    exit(1);
  if ((res = execve(bin, args, env)) == -1)
    my_puterr(ERR_EXECVE);
}

int		father_process_action(int son_pid)
{
  int		son_status;

  while (wait(&son_status) != son_pid);
  if (WIFSIGNALED(son_status) == 1 && WTERMSIG(son_status) == SIGSEGV)
    my_puterr(ERR_SEGMENTATION_FAULT);
  else if (WIFSIGNALED(son_status) == 1 && WTERMSIG(son_status) == SIGFPE)
    my_puterr(ERR_FLOATING_PTS_EXCP);
  return (son_status);
}
