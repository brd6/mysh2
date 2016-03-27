/*
** parser_checker.c for parser_checker in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Mar 27 03:48:59 2016 Berdrigue BONGOLO BETO
** Last update Sun Mar 27 04:13:34 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"
#include "parser.h"

int		is_operators(char *str)
{
  if (!my_strcmp(str, OP_PIPE) ||
      !my_strcmp(str, OP_AND) ||
      !my_strcmp(str, OP_R_REDIRECT) ||
      !my_strcmp(str, OP_RR_REDIRECT) ||
      !my_strcmp(str, OP_L_REDIRECT) ||
      !my_strcmp(str, OP_LL_REDIRECT))
    return (1);
  return (0);
}

int		check_operator(t_list2 *list, char *str)
{
  if (list != NULL &&
      is_operators(str) &&
      (check_operator(list->prev, str) || check_command(list->prev, str)))
    return (1);
  return (0);
}

int		check_command(t_list2 *list, char *str)
{
  if (list == NULL ||
      !check_operator(list, str) ||
      check_operator(list->prev, str))
    return (1);
  return (0);
}

int		check_option(t_list2 *list, char *str)
{
  if (list != NULL && check_command(list->prev, str))
    return (1);
  return (0);
}
