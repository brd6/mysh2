/*
** fork_action.c for fork_action in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Apr  3 15:04:05 2016 Berdrigue BONGOLO BETO
** Last update Sun Apr  3 23:24:27 2016 Berdrigue BONGOLO BETO
*/

/* #include <signal.h> */
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"

void		son_process_action(char *bin, char **env, t_cmd *cmd)
{
  int		res;

  if (!check_bin_permission(bin))
    exit(1);
  /* signal(SIGINT, SIG_DFL); */

  // redirection
  /* if (cmd->redirect[0].file != NULL) */
  /*   { */
  /*     if (cmd->redirect[0].is_at_begin) */
  /* 	{ */
  /* 	  if (!my_strcmp(cmd->redirect[0].type, OP_LL_REDIRECT)) */
  /* 	    { */
  /* 	      // exec my heredoc */
  /* 	      printf("heredoc\n"); */
  /* 	    } */
  /* 	  else if (!my_strcmp(cmd->redirect[0].type, OP_L_REDIRECT)) */
  /* 	    { */
  /* 	      // exec < redirection */
  /* 	      printf("sd2\n"); */
  /* 	      if (!redirect_left(0, cmd->redirect[0].file)) */
  /* 		return; */
  /* 	    } */
  /* 	  else if (!my_strcmp(cmd->redirect[0].type, OP_R_REDIRECT)) */
  /* 	    { */
  /* 	      // exec > redirection */
  /* 	      printf("sd\n"); */
  /* 	      if (!redirect_right(0, cmd->redirect[0].file)) */
  /* 		return; */
  /* 	    } */
  /* 	} */
  /*   } */
  if (!redirect_cmd(cmd))
    return;
  if ((res = execve(bin, cmd->options, env)) == -1)
    my_puterr(ERR_EXECVE);
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
