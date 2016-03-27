/*
** convert_base.c for convert_base in /home/bongol_b/rendu/Piscine_C_J08/ex_05
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Oct  8 18:40:38 2015 berdrigue bongolo-beto
** Last update Thu Feb 11 20:23:58 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"

int	set_sign(char *convert_res, int *isneg, int *i, int flag)
{
  if (flag)
    {
      if (*isneg == 1)
	{
	  convert_res[*i] = '-';
	  *i = *i + 1;
	}
    }
  else
    {
      *isneg = 1;
      return (1);
    }
  return (0);
}

char	*return_zerobase(char *base)
{
  char	*c;

  c = malloc(sizeof(char) * 2);
  if (c == NULL)
    return (NULL);
  c[0] = base[0];
  c[1] = 0;
  return (c);
}

char	*convert_base(char *nbr, char *base_from, char *base_to)
{
  int	i;
  int	nbr_base;
  char	*convert_res;
  int	baseto_len;
  int	neg;

  i = 0;
  neg = 0;
  nbr_base = my_getnbr_base(nbr, base_from);
  if (nbr_base == 0)
    return (return_zerobase(base_to));
  if ((convert_res = malloc(sizeof(*nbr) * (nbr_base + 3))) == NULL)
    return (NULL);
  if (nbr[0] == '-' && set_sign(convert_res, &neg, &i, 0) == 1)
    nbr = nbr + 1;
  baseto_len = my_strlen(base_to);
  while (nbr_base > 0)
    {
      convert_res[i++] = base_to[nbr_base % baseto_len];
      nbr_base = nbr_base / baseto_len;
    }
  set_sign(convert_res, &neg, &i, 1);
  convert_res[i] = 0;
  return (my_revstr(convert_res));
}
