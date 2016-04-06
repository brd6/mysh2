/*
** builtin_cd.c<builtins> for builtin_cd in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Apr  5 17:31:23 2016 Berdrigue BONGOLO BETO
** Last update Wed Apr  6 16:35:46 2016 Berdrigue BONGOLO BETO
*/

#include <unistd.h>
#include <stdlib.h>
#include <linux/limits.h>
#include "my.h"
#include "my_printf.h"
#include "mysh.h"

int		find_key(char *data, char *data_ref)
{
  return ((my_strstr(data, data_ref) != NULL) ? 0 : 1);
}

char		*get_goto_dir(t_mysh *mysh, char **args)
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
  if (!my_strcmp(args[1], "-") && env_key_exist(mysh->my_env, "OLDPWD"))
    return (key_to_value(mysh->my_env, "OLDPWD"));
  return (my_strdup(args[1]));
}

void		builtin_cd_replacing_pwd(t_mysh *mysh, char *cwd, char *flag)
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

int		builtin_cd(t_mysh *mysh, t_cmd *cmd)
{
  char		*goto_dir;
  int		res;
  char		buf[PATH_MAX + 1];
  char		*cwd;

  if ((goto_dir = get_goto_dir(mysh, cmd->options)) == NULL)
    return (0);
  if (access(goto_dir, F_OK) != 0)
    return (my_printf(ERR_FILE_NOEXIST, goto_dir));
  if (access(goto_dir, R_OK) != 0)
    return (my_printf(ERR_FILE_NOACCESS, goto_dir));
  if ((cwd = getcwd(buf, PATH_MAX + 1)) == NULL)
    return (my_putstr(ERR_GETWCD), 0);
  builtin_cd_replacing_pwd(mysh, cwd, "OLDPWD");
  if ((res = chdir(goto_dir)) == -1 ||
      (cwd = getcwd(buf, PATH_MAX + 1)) == NULL)
    return (my_printf(ERR_NODIRECTORY, goto_dir));
  if (!env_key_exist(mysh->my_env, "PWD"))
    return (0);
  builtin_cd_replacing_pwd(mysh, cwd, "PWD");
  free(goto_dir);
  return (1);
}
