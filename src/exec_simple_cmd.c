/*
** exec_simple_cmd.c for exec_simple_cmd in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Apr  1 18:08:23 2016 Berdrigue BONGOLO BETO
** Last update Sun Apr  3 12:30:11 2016 Berdrigue BONGOLO BETO
*/

#include "mysh.h"

int		exec_simple_cmd(t_mysh *mysh,
				t_cmd *cmd,
				t_my_builtin *builtins)
{
  // is_at_begin a check avant (redirection avant)

  int		i;

  i = 0;
  while (cmd->options[i])
    {
      printf("%s\n", cmd->options[i]);
      i++;
    }
}
