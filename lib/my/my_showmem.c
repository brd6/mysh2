/*
** my_showmem.c for my_showmem in /home/bongol_b/rendu/Piscine_C_J06
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Oct  6 23:17:59 2015 berdrigue bongolo-beto
** Last update Wed Feb 10 13:55:44 2016 Berdrigue BONGOLO BETO
*/

#include "my.h"

void	show_first_char_addr(char *str)
{
  my_putnbr_base(str[0],"0123456789abcdef");
  my_putchar(':');
  my_putchar(' ');
}

void	show_hexa_content(char *str, int i, int read_max, int size)
{
  while (i < read_max && i < size)
    {
      if (str[i] < 32)
	my_putchar('0');
      my_putnbr_base(str[i], "0123456789abcdef");
      if (i % 2 == 1)
	my_putchar(' ');
      i = i + 1;
    }
}

void	show_content(char *str, int read_min, int read_max, int size)
{
  int	i;

  i = read_min;
  my_putchar(' ');
  while (i < read_max && i < size)
    {
      if (is_printable(str[i]))
	my_putchar(str[i]);
      else
	my_putchar('.');
      i = i + 1;
    }
}

int	my_showmem(char *str, int size)
{
  int	i;
  int	max_line;
  int	read_min;
  int	read_max;

  i = 0;
  max_line = 16;
  read_min = 0;
  read_max = max_line;
  while (i < size)
    {
      if (i % max_line == 0)
	{
	  show_first_char_addr(&str[read_min]);
	  show_hexa_content(str, read_min, read_max, size);
	  show_content(str, read_min, read_max, size);
	  read_min = read_min + max_line;
	  read_max = (read_max + max_line > size) ? size : read_max + max_line;
	  my_putchar('\n');
	}
      i = i + 1;
    }
  return (0);
}
