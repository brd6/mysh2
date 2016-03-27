/*
** my_wordtab_count.c for my_wordtab_count in /home/bongol_b/rendu/PSU_2015_minishell1/lib/my
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Jan  8 02:36:27 2016 Berdrigue BONGOLO BETO
** Last update Fri Jan  8 02:38:29 2016 Berdrigue BONGOLO BETO
*/

int		my_wordtab_count(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
