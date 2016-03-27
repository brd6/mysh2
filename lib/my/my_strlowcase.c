/*
** my_strlowcase.c for my_strlowcase in /home/bongol_b/rendu/Piscine_C_J06
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Oct  5 15:48:22 2015 berdrigue bongolo-beto
** Last update Mon Dec 28 13:09:17 2015 berdrigue bongolo-beto
*/

char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	  str[i] = str[i] + 32;
      i = i + 1;
    }
  return (str);
}
