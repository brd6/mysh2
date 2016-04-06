/*
** builtin_env.c<builtins> for builtin_env in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Wed Apr  6 20:45:54 2016 Berdrigue BONGOLO BETO
** Last update Wed Apr  6 20:51:03 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

void		print_env(void *data)
{
  my_putstr(data);
  my_putchar('\n');
}

int		builtin_env(t_mysh *mysh, t_cmd *cmd)
{
  my_apply_on_list(mysh->my_env, print_env);
  return (1);
}
