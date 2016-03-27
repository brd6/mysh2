/*
** my_is_prime.c for my_is_prime in /home/bongol_b/rendu/Piscine_C_J05
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Oct  3 00:07:04 2015 berdrigue bongolo-beto
** Last update Fri Oct 16 18:00:55 2015 berdrigue bongolo-beto
*/

int	my_is_prime(int nb)
{
  int	i;
  int	is_prime;
  int	found;
  int	limit;

  i = 3;
  is_prime = 1;
  found = 0;
  limit = nb;

  if (nb < 2 || (nb % 2 == 0 && nb != 2) || nb > 2147483647)
    return (0);
  while (i < limit && found == 0)
    {
      if (nb % i == 0)
	{
	  is_prime = 0;
	  found = 1;
	}
      i = i + 2;
    }
  return (is_prime);
}
