/*
** list_utils.c for list_utils in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Mar 28 19:37:16 2016 Berdrigue BONGOLO BETO
** Last update Wed Apr  6 23:30:05 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
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
