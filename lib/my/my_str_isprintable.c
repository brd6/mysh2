/*
** my_str_isprintable.c for my_str_isprintable in /home/bongol_b/rendu/Piscine_C_J06
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Oct  5 17:34:50 2015 berdrigue bongolo-beto
** Last update Mon Dec 28 13:08:12 2015 berdrigue bongolo-beto
*/

int	is_printable(char c)
{
  return (c >= ' ' && c <= '~');
}

int	my_str_isprintable(char *str)
{
  while (*str && is_printable(*str))
    str = str + 1;
  return (!(*str));
}
