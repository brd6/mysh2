/*
** exec_simple_cmd.c for exec_simple_cmd in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Apr  1 18:08:23 2016 Berdrigue BONGOLO BETO
** Last update Sun Apr  3 15:32:25 2016 Berdrigue BONGOLO BETO
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"

void		execute_cmd_system(t_mysh *mysh, char **args)
{
  pid_t		son_pid;
  char		**env;
  char		*bin;

  if (((env = env_list_to_array(mysh->my_env)) == NULL) ||
      (bin = get_bin_path(args[0], key_to_value(mysh->my_env, "PATH"))) == NULL)
    {
      free(env);
      free(bin);
    }
  if ((son_pid = fork()) == -1)
    {
      free(env);
      free(bin);
      my_puterr(ERR_FORK);
    }
  if (son_pid == 0)
    son_process_action(bin, env, args);
  else
    father_process_action(son_pid);
  free(bin);
  free(env);
}

int		exec_simple_cmd(t_mysh *mysh,
				t_cmd *cmd,
				t_my_builtin *builtins)
{
  // is_at_begin a check avant (redirection avant)
  int		builtin_index;

  if ((builtin_index = is_builins_cmd(cmd->command, builtins)) != -1)
    {
      return (builtins[builtin_index].func(mysh, cmd));
    }
  else
    {
      /* exec_cmd_system(); */
      execute_cmd_system(mysh, cmd->options);
    }
}
