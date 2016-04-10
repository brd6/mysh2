/*
** builtin_cd.c<builtins> for builtin_cd in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Apr  5 17:31:23 2016 Berdrigue BONGOLO BETO
** Last update Sun Apr 10 16:53:35 2016 Berdrigue BONGOLO BETO
*/

#include <unistd.h>
#include <stdlib.h>
#include <linux/limits.h>
#include "my.h"
#include "my_printf.h"
#include "mysh.h"

static char	*get_goto_dir(t_mysh *mysh, char **args, char *oldpwd)
{
  char		*home_val;

  if ((args[1] == NULL || args[1][0] == 0) &&
      !env_key_exist_v(mysh->my_env, "HOME"))
    return (NULL);
  if (!env_key_exist(mysh->my_env, "HOME"))
    return (my_strdup(args[1]));
  home_val = key_to_value(mysh->my_env, "HOME");
  if (args[1] != NULL && my_strstr(args[1], "~") != NULL)
    return (my_str_replace("~", home_val, args[1], 1));
  if (args[1] == NULL || args[1][0] == 0)
    return (home_val);
  if (!my_strcmp(args[1], "-") && oldpwd != NULL)
    return (oldpwd);
  return (my_strdup(args[1]));
}

static void	builtin_cd_replacing_pwd(t_mysh *mysh, char *cwd, char *flag)
{
  char		*pwd_value;
  t_list	*tmp;

  if (!env_key_exist(mysh->my_env, flag))
    return;
  tmp = my_find_node_eq_in_list(mysh->my_env, flag, find_key);
  pwd_value = key_to_value(mysh->my_env, flag);
  if (cwd != NULL)
    tmp->data = my_str_replace(pwd_value, cwd, tmp->data, 1);
  free(pwd_value);
}

static int	check_for_error(char *goto_dir)
{
  char		*err_tmp;

  if (access(goto_dir, F_OK) != 0)
    {
      err_tmp = my_str_replace("%s", goto_dir, ERR_FILE_NOEXIST, 1);
      return (my_puterr(err_tmp), 0);
    }
  if (access(goto_dir, R_OK) != 0)
    {
      err_tmp = my_str_replace("%s", goto_dir, ERR_FILE_NOACCESS, 1);
      return (my_puterr(err_tmp), 0);
    }
  return (1);
}

int		builtin_cd(t_mysh *mysh, t_cmd *cmd)
{
  static char	*oldpwd;
  char		*goto_dir;
  int		res;
  char		buf[PATH_MAX + 1];
  char		*cwd;

  if ((goto_dir = get_goto_dir(mysh, cmd->options, oldpwd)) == NULL ||
      !check_for_error(goto_dir))
    return (0);
  if ((cwd = getcwd(buf, PATH_MAX + 1)) == NULL)
    return (my_puterr(ERR_GETWCD), 0);
  oldpwd = my_strdup(cwd);
  if ((res = chdir(goto_dir)) == -1 ||
      (cwd = getcwd(buf, PATH_MAX + 1)) == NULL)
    return (my_puterr(my_str_replace("%s", goto_dir, ERR_NODIRECTORY, 1)), 0);
  if (!env_key_exist(mysh->my_env, "PWD"))
    return (0);
  builtin_cd_replacing_pwd(mysh, cwd, "PWD");
  free(goto_dir);
  return (1);
}
