/*
** redirect_cmd.c for redirect_cmd in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Apr  3 18:50:41 2016 Berdrigue BONGOLO BETO
** Last update Sun Apr  3 19:08:58 2016 Berdrigue BONGOLO BETO
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
