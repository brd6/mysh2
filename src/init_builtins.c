/*
** init_builtins.c for init_builtins in /home/bongol_b/rendu/PSU_2015_minishell1
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Wed Jan 13 21:26:09 2016 Berdrigue BONGOLO BETO
** Last update Sun Apr  3 15:33:56 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

void		init_builtin_struct(t_my_builtin *builtin,
				    char *name,
				    int (*func)(t_mysh *mysh, t_cmd *cmd))
{
  builtin->name = name;
  builtin->func = func;
}

int		is_builins_cmd(char *cmd, t_my_builtin *builtins)
{
  int		i;

  i = 0;
  while (builtins[i].name != NULL)
    {
      if (my_strcmp(builtins[i].name, cmd) == 0)
	return (i);
      i = i + 1;
    }
  return (-1);
}

void		init_builtins(t_my_builtin *builtins)
{
  init_builtin_struct(&builtins[0], "exit", &builtin_exit);
  init_builtin_struct(&builtins[1], NULL, NULL);
  /* init_builtin_struct(&builtins[1], "cd", &builtin_cd); */
  /* init_builtin_struct(&builtins[2], "env", &builtin_env); */
  /* init_builtin_struct(&builtins[3], "history_", &builtin_exit); */
  /* init_builtin_struct(&builtins[4], "setenv", &builtin_setenv); */
  /* init_builtin_struct(&builtins[5], "unsetenv", &builtin_unsetenv); */
  /* init_builtin_struct(&builtins[6], "exit", &builtin_exit); */
  /* init_builtin_struct(&builtins[7], "help", &builtin_help); */
  /* init_builtin_struct(&builtins[8], NULL, NULL); */
}
