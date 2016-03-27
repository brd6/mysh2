/*
** my_find_prime_sup.c for my_find_prime_sup in /home/bongol_b/rendu/Piscine_C_J05
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Oct  3 00:28:05 2015 berdrigue bongolo-beto
** Last update Wed Feb 10 13:53:47 2016 Berdrigue BONGOLO BETO
*/

#include "my.h"

int	my_find_prime_sup(int nb)
{
  if (nb > 2 && nb % 2 == 0)
    nb = nb + 1;
  if (!my_is_prime(nb))
    nb = nb + 2;
  else
    return (nb);
  return (my_find_prime_sup(nb));
}
