/*
** prompt.c for prompt in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Mar 29 11:31:28 2016 Berdrigue BONGOLO BETO
** Last update Tue Mar 29 12:57:28 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

char		*shorten_pwd(t_mysh *mysh, char *env_pwd)
{
  char		*home;

  home = key_to_value(mysh->my_env, "HOME");
  if (home != NULL && my_strstr(env_pwd, home) != NULL)
    {
      return (my_str_replace(home, "~", env_pwd, -1));
    }
  return (my_strdup(env_pwd));
}

void		set_prompt(t_mysh *mysh, char *env_pwd)
{
  char		*prompt;
  char		*shortpwd;

  shortpwd = shorten_pwd(mysh, env_pwd);
  prompt = my_strdup("\033[1m%s1\033[0m> ");
  g_prompt = my_str_replace("%s1", shortpwd, prompt, 1);
  free(prompt);
  free(shortpwd);
}

void		show_prompt(t_mysh *mysh)
{
  char		*env_pwd;

  if (env_key_exist(mysh->my_env, "PWD") &&
      (env_pwd = key_to_value(mysh->my_env, "PWD")))
    {
      set_prompt(mysh, env_pwd);
      my_putstr(g_prompt);
      free(env_pwd);
    }
  else
    {
      g_prompt = my_strdup("$> ");
      my_putstr(g_prompt);
    }
}
