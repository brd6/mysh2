/*
** my_isneg.c for my_isneg in /home/bongol_b/rendu/Piscine_C_J03
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Wed Sep 30 11:09:33 2015 berdrigue bongolo-beto
** Last update Wed Feb 10 13:57:57 2016 Berdrigue BONGOLO BETO
*/

#include "my.h"

int	my_isneg(int n)
{
  if (n >= 0)
    my_putchar('P');
  else
    my_putchar('N');
  return (0);
}
