/*
** builtin_setenv.c for builtin_setenv in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Wed Apr  6 23:58:22 2016 Berdrigue BONGOLO BETO
** Last update Thu Apr  7 00:10:46 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int		syntax_env_key(char *key)
{
  if (!is_alpha(key[0]))
    return (my_puterr(ERR_SETENV_VARNAME1), 0);
  if (!my_str_isalphanum(key))
    return (my_puterr(ERR_SETENV_VARNAME2), 0);
  return (1);
}

int		builtin_setenv_cond(t_list *my_env, char **args)
{
  t_list	*tmp;
  char		*new_elem;

  new_elem = concat_two_str(args[1], args[2], "=");
  if (env_key_exist(my_env, args[1]))
    {
      tmp = my_find_node_eq_in_list(my_env, args[1], find_key);
      tmp->data = new_elem;
      return (1);
    }
  else
    {
      if (!my_add_elem_in_list_end(&my_env, new_elem))
	return (my_puterr(ERR_SETENV_MALLOC), 0);
      return (1);
    }
}

int		builtin_setenv(t_mysh *mysh, t_cmd *cmd)
{
  if (cmd->options[0] == NULL || cmd->options[1] == NULL)
    return (builtin_env(mysh, cmd));
  if (!syntax_env_key(cmd->options[1]))
    return (GO_ON);
  return (builtin_setenv_cond(mysh->my_env, cmd->options));
}
