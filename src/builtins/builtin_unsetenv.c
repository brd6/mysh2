/*
** builtin_unsetenv.c<builtins> for builtin_unsetenv in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Apr  7 00:18:25 2016 Berdrigue BONGOLO BETO
** Last update Thu Apr  7 00:19:59 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "mysh.h"

int		builtin_unsetenv(t_mysh *mysh, t_cmd *cmd)
{
  if (cmd->options[1] != NULL && env_key_exist(mysh->my_env, cmd->options[1]))
    my_rm_all_eq_from_list(&mysh->my_env, cmd->options[1], find_key);
  return (1);
}
