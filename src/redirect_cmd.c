/*
** redirect_cmd.c for redirect_cmd in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Apr  3 18:50:41 2016 Berdrigue BONGOLO BETO
** Last update Mon Apr  4 01:48:29 2016 Berdrigue BONGOLO BETO
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"

static void	print_list_str(void *str)
{
  my_putstr((char *)str);
  my_putchar('\n');
}

int		redirect_left(char *type, char *filename)
{
  int		fd;
  t_list	*heredoc;

  if (my_strcmp(type, OP_LL_REDIRECT) != 0)
    {
      if ((fd = open(filename, O_RDONLY)) == -1)
	return (my_puterr(ERR_OPEN_FILE), 0);
    }
    else
      fd = 1;
  if (fd == 1)
    {
      heredoc = my_heredoc(filename);
      my_apply_on_list(heredoc, print_list_str);
    }
  if (dup2(fd, 0) == -1)
    return (my_puterr(ERR_DUP2), 0);
  return (1);
}

int		redirect_right(char *type, char *filename)
{
  int		fd;
  int		at_end;

  at_end = (type[1] != 0) ? FLG_FILE_CWRITE2 : FLG_FILE_CWRITE;
  if ((fd = open(filename, at_end, FLG_FILE_PERM)) == -1)
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
      if (cmd->redirect[i].type[0] == OP_LL_REDIRECT[0] &&
	  !redirect_left(cmd->redirect[i].type, cmd->redirect[i].file))
	{
	  /* printf("heredoc\n"); */
	  return (0);
	}
      else if (cmd->redirect[i].type[0] == OP_R_REDIRECT[0] &&
	       !redirect_right(cmd->redirect[i].type, cmd->redirect[i].file))
	{
	  // exec > redirection
	  return (0);
	}
      i++;
    }
  return (1);
}
