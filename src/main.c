/*
** main.c for main in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Mar 20 21:57:42 2016 Berdrigue BONGOLO BETO
** Last update Tue Apr 12 17:04:13 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include <signal.h>
#include "my.h"
#include "get_next_line.h"
#include "mysh.h"

void	mysh_loop(t_mysh *mysh)
{
  t_my_builtin	builtins[6];
  char		*line;
  t_list	*cmds;

  init_builtins(builtins);
  while (1)
    {
      my_putstr(PROMPT);
      if (!check_null_line((line = get_next_line(0))))
	break;
      if (!is_space_str(line) &&
      	  (cmds = check_valid_line(line)) != NULL &&
      	  exec_multi_cmd(mysh, cmds, builtins) == EXIT_PROG)
      	break;
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
      if (mysh.my_env == NULL || !my_rev_list(&mysh.my_env))
  	return (my_putstr(ERR_MALLOC), 1);
    }
  mysh_loop(&mysh);
  free_mysh(&mysh);
  return (mysh.exit_code);
}
