/*
** my_heredoc.c for my_heredoc in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Apr  3 14:45:26 2016 Berdrigue BONGOLO BETO
** Last update Mon Apr  4 01:19:51 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include <signal.h>
#include "my.h"
#include "get_next_line.h"
#include "mylist.h"
#include "mysh.h"

t_list		*my_heredoc(char *eof)
{
  t_list	*list;
  char		*line;

  list = NULL;
  signal(SIGINT, SIG_IGN);
  while (1)
    {
      my_putstr("? ");
      line = get_next_line(0);
      if (line == NULL || !my_strcmp(line, eof))
	break;
      my_add_elem_in_list_end(&list, my_strdup(line));
    }
  return (list);
}
