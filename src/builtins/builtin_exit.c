/*
** builtin_exit.c<src> for builtin_exit in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Apr  1 17:21:16 2016 Berdrigue BONGOLO BETO
** Last update Sun Apr 10 14:53:07 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int		builtin_exit(t_mysh *mysh, t_cmd *cmd)
{
  if (cmd->options[1] == NULL || cmd->options[1][0] == 0)
    {
      mysh->exit_code = 0;
      my_putstr(EXIT_MSG);
      return (EXIT_PROG);
    }
  if (!my_str_isnum(cmd->options[1]) || cmd->options[2] != NULL)
    {
      mysh->exit_code = 1;
      my_puterr(ERR_EXIT_EXPR_SYNTAX);
      return (GO_ON);
    }
  mysh->exit_code = my_getnbr(cmd->options[1]) % 256;
  my_putstr(EXIT_MSG);
  return (EXIT_PROG);
}
