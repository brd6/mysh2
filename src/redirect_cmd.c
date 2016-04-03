/*
** redirect_cmd.c for redirect_cmd in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Apr  3 18:50:41 2016 Berdrigue BONGOLO BETO
** Last update Sun Apr  3 23:23:44 2016 Berdrigue BONGOLO BETO
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"

int		redirect_left(int is_double, char *filename)
{
  int		fd;

  if ((fd = open(filename, O_RDONLY)) == -1)
    return (my_puterr(ERR_OPEN_FILE), 0);
  if (dup2(fd, 0) == -1)
    return (my_puterr(ERR_DUP2), 0);
  return (1);
}

int		redirect_right(int is_double, char *filename)
{
  int		fd;

  if ((fd = open(filename, FLG_FILE_CWRITE, FLG_FILE_PERM)) == -1)
    return (my_puterr(ERR_OPEN_FILE), 0);
  if (dup2(fd, 1) == -1)
    return (my_puterr(ERR_DUP2), 0);
  return (1);
}

int		redirect_cmd(t_cmd *cmd)
{
  int		i;

  i = 0;
  while (cmd->redirect[i].file != NULL)
    {
      if (!my_strcmp(cmd->redirect[i].type, OP_LL_REDIRECT))
	{
	  // exec my heredoc
	  printf("heredoc\n");
	}
      else if (!my_strcmp(cmd->redirect[i].type, OP_L_REDIRECT))
	{
	  // exec < redirection
	  if (!redirect_left(0, cmd->redirect[i].file))
	    return (0);
	}
      else if (!my_strcmp(cmd->redirect[i].type, OP_R_REDIRECT))
	{
	  // exec > redirection
	  if (!redirect_right(0, cmd->redirect[i].file))
	    return (0);
	}
      i++;
    }
  return (1);
}
