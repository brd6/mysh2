/*
** my_showstr.c for my_showstr in /home/bongol_b/rendu/Piscine_C_J06
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Oct  6 23:03:58 2015 berdrigue bongolo-beto
** Last update Wed Feb 10 13:44:05 2016 Berdrigue BONGOLO BETO
*/

#include "my.h"

int	showstr_is_printable(char c)
{
  return (c >= ' ' && c <= '~');
}

int	my_showstr(char *str)
{
  while (*str)
    {
      if (showstr_is_printable(*str))
	my_putchar(*str);
      else
	{
	  my_putchar('\\');
	  if (*str < ' ')
	    my_putchar('0');
	  my_putnbr_base(*str, "0123456789abcdef");
	}
      str = str + 1;
    }
  return (0);
}
