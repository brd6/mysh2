/*
** my_putnbr_base.c for my_putnbr_base in /home/bongol_b/rendu/Piscine_C_J06
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Oct  6 09:01:45 2015 berdrigue bongolo-beto
** Last update Wed Feb 10 14:00:22 2016 Berdrigue BONGOLO BETO
*/

#include "my.h"

int	my_putnbr_base_len(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}

int	my_putnbr_base(int nbr, char *base)
{
  int	base_len;

  base_len = my_putnbr_base_len(base);
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = nbr * (-1);
    }
  if (nbr >= base_len)
    my_putnbr_base(nbr / base_len, base);
  my_putchar(base[nbr % base_len]);
  return (nbr);
}
