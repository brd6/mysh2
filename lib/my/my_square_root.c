/*
** my_square_root.c for my_square_root in /home/bongol_b/rendu/Piscine_C_J05
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Oct  2 13:23:59 2015 berdrigue bongolo-beto
** Last update Mon Dec 28 13:05:01 2015 berdrigue bongolo-beto
*/

int	my_square_root(int nb)
{
  int	n;
  int	res;

  n = 1;
  res = nb;
  if (res >= 2147483647)
    {
      res = ((res - 1) / 2) + 1;
      n = nb / res;
    }
  while (res > n)
    {
      res = (res + n) / 2;
      n = nb / res;
    }
  if (res * res == nb)
    return res;
  return 0;
}
