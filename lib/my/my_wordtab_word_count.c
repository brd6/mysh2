/*
** my_wordtab_word_count.c for my_wordtab_word_count in /home/bongol_b/rendu_ok/PSU_2015_minishell1
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Jan 19 20:34:47 2016 Berdrigue BONGOLO BETO
** Last update Wed Feb 10 13:58:19 2016 Berdrigue BONGOLO BETO
*/

#include "my.h"

int		my_wordtab_word_count(char **args)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (args[i])
    j += my_strlen(args[i++]);
  return (j);
}
