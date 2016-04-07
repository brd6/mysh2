/*
** my_heredoc.c for my_heredoc in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Apr  3 14:45:26 2016 Berdrigue BONGOLO BETO
** Last update Thu Apr  7 19:37:18 2016 Berdrigue BONGOLO BETO
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "my.h"
#include "get_next_line.h"
#include "mylist.h"
#include "mysh.h"

char		*filewrite_heredoc(t_list *list)
{
  t_list	*tmp;
  int		fd;
  char		*filename;

  tmp = list;
  filename = directory_exist("/tmp/") ? HEREDOC_TMP1 : HEREDOC_TMP2;
  filename = my_str_replace("%pid%", my_itoa(getpid()), filename, 1);
  /* printf("%d\n",getpid() ); */
  if ((fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, FLG_FILE_PERM)) == -1)
    return (NULL);
  while (tmp != NULL)
    {
      if (write(fd, tmp->data, my_strlen(tmp->data)) == -1)
	return (NULL);
      if (write(fd, "\n", 1) == -1)
	return (NULL);
      tmp = tmp->next;
    }
  close(fd);
  return (filename);
}

/* void		delete_heredoc_filetmp(char *filename, char **env) */
/* { */
/*   char		**cmd; */

/*   if ((cmd = malloc(sizeof(*cmd) * (4))) == NULL) */
/*     return; */
/*   cmd[0] = my_strdup("rm"); */
/*   cmd[1] = my_strdup("-f"); */
/*   cmd[2] = my_strdup(filename); */
/*   cmd[3] = NULL; */
/*   execve("/bin/rm", cmd, env); */
/* } */

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
