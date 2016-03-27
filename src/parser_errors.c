/*
** parser_errors.c for parser_errors in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Mar 27 15:44:09 2016 Berdrigue BONGOLO BETO
** Last update Sun Mar 27 17:37:09 2016 Berdrigue BONGOLO BETO
*/

#include "my.h"
#include "parser.h"

void		print_error_unmatched(char c)
{
  char		s[2];

  my_puterr("Unmatched ");
  s[0] = c;
  s[1] = 0;
  my_puterr(s);
  my_puterr(".\n");
}

void		exit_on_error(char *msg)
{
  my_puterr(msg);
  exit(-1);
}
