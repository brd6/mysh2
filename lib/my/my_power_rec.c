/*
** my_power_rec.c for my_power_rec in /home/bongol_b/rendu/Piscine_C_J05
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Oct  2 12:43:41 2015 berdrigue bongolo-beto
** Last update Mon Dec 28 12:57:07 2015 berdrigue bongolo-beto
*/

int	my_power_rec(int nb, int power)
{
  int	res;
  int	max_int;

  res = 1;
  max_int = 2147483647;
  if (power < 0 || nb < 0)
    return 0;
  if (power == 0)
    return 1;
  res = nb * my_power_rec(nb, power - 1);
  return (res < 0 || res > max_int) ? 0 : res;
}
