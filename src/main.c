/*
** main.c for main in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Mar 20 21:57:42 2016 Berdrigue BONGOLO BETO
** Last update Tue Mar 29 13:15:39 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include <signal.h>
#include "my.h"
#include "get_next_line.h"
#include "mysh.h"

char		*g_prompt;

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
      if (!is_space_str(line))
	{
	  check_valid_line(line);
	  // record command in history list
	}
      free(line);
    }
  free(line);
}

int		main(int ac, char **av, char **envn)
{
  t_mysh	mysh;

  (void)(ac);
  (void)(av);
  signal(SIGINT, sig_handler_sigint);
  mysh.exit_code = 0;
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
