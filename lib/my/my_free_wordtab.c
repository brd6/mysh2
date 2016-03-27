/*
** my_free_wordtab.c for my_free_wordtab in /home/bongol_b/Epitech-rendu/libmy
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Feb 21 18:52:03 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 12 13:56:46 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>

void		my_free_wordtab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}
