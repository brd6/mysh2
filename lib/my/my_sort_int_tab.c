/*
** my_sort_int_tab.c for my_sort_int_tab in /home/bongol_b/rendu/Piscine_C_J04
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Oct  1 22:12:32 2015 berdrigue bongolo-beto
** Last update Mon Dec 28 13:05:14 2015 berdrigue bongolo-beto
*/

void	my_int_swap(int *a, int *b)
{
  int	tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

void	my_sort_int_tab(int *tab, int size)
{
  int	min_nbr;
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < size)
    {
      j = i;
      min_nbr = i;
      while (j < size)
	{
	  if (tab[j] < tab[min_nbr])
	    min_nbr = j;
	  j = j + 1;
	}
      my_int_swap(&tab[i], &tab[min_nbr]);
      i = i + 1;
    }
}
