/*
** my_strupcase.c for my_strupcase in /home/bongol_b/rendu/Piscine_C_J06
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Oct  5 15:43:47 2015 berdrigue bongolo-beto
** Last update Mon Dec 28 13:23:10 2015 berdrigue bongolo-beto
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	str[i] = str[i] - 32;
      i = i + 1;
    }
  return (str);
}
