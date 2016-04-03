/*
** builtin_exit.c<src> for builtin_exit in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Apr  1 17:21:16 2016 Berdrigue BONGOLO BETO
** Last update Sun Apr  3 13:51:53 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int		builtin_exit(t_mysh *mysh, t_cmd *cmd)
{
  if (cmd->options[1] == NULL || cmd->options[1][0] == 0)
    {
      mysh->exit_code = 0;
      my_putstr("exit\n");
      return (EXIT_PROG);
    }
  if (!my_str_isnum(cmd->options[1]) || cmd->options[2] != NULL)
    {
      mysh->exit_code = 1;
      my_puterr("exit: Expression Syntax.\n");
      return (GO_ON);
    }
  mysh->exit_code = my_getnbr(cmd->options[1]) % 256;
  my_putstr("exit\n");
  return (EXIT_PROG);
}
