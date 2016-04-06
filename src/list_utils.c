/*
** list_utils.c for list_utils in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Mar 28 19:37:16 2016 Berdrigue BONGOLO BETO
** Last update Thu Apr  7 00:10:05 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "my_printf.h"
#include "parser.h"

void		print_list2_handler(void *data)
{
  t_parser	*parser;

  if (data == NULL)
    return;
  parser = ((t_parser *)(data));
  my_printf("'%s' (%d)\n", parser->token, parser->type);
}

int		find_key(char *data, char *data_ref)
{
  return ((my_strstr(data, data_ref) != NULL) ? 0 : 1);
}
