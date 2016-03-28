/*
** main.c for main in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Mar 20 21:57:42 2016 Berdrigue BONGOLO BETO
** Last update Tue Mar 29 00:22:20 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include <signal.h>
#include "my.h"
#include "get_next_line.h"
#include "mysh.h"

char		*g_prompt;

int		option_handler(t_mysh *mysh, char **av)
{
  /* if (!my_strcmp(av[1], "--help")) */
  /*   { */
  /*     builtin_help(mysh, av); */
  /*     return (0); */
  /*   } */
  /* return (1); */
}

void		show_prompt(t_mysh *mysh)
{
  char		*env_pwd;

  if (env_key_exist(mysh->my_env, "PWD") &&
      (env_pwd = key_to_value(mysh->my_env, "PWD")))
    {
      g_prompt = my_str_replace("%s", env_pwd, "%s> ", 1);
      my_putstr(g_prompt);
      free(env_pwd);
    }
  else
    {
      g_prompt = my_strdup("$> ");
      my_putstr(g_prompt);
    }
}

void		mysh_loop(t_mysh *mysh)
{
  int		status;
  t_my_builtin	builtins[9];
  char		*line;

  init_builtins(builtins);
  while (1)
    {
      show_prompt(mysh);
      line = get_next_line(0);
      if (!check_null_line(line))
	break;
      // check_correct_line
      check_valid_line(line);
      // record command in history list
      free(line);
    }
  free(line);
}

int		main(int ac, char **av, char **envn)
{
  t_mysh	mysh;

  signal(SIGINT, sig_handler_sigint);
  mysh.exit_code = 0;
  if (ac == 2 && !option_handler(&mysh, av))
    return (0);
  if (envn == NULL || envn[0] == 0)
    mysh.my_env = NULL;
  else
    {
      mysh.my_env = my_params_in_list(my_wordtab_count(envn), envn);
      if (mysh.my_env == NULL)
	return (my_putstr("Malloc error\n"), 1);
      my_rev_list(&mysh.my_env);
    }
  mysh_loop(&mysh);
  free_mysh(&mysh);
  return (mysh.exit_code);
}
