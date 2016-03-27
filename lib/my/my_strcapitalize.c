/*
** my_strcapitalize.c for my_strcapitalize in /home/bongol_b/rendu/Piscine_C_J06
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Oct  5 15:53:15 2015 berdrigue bongolo-beto
** Last update Mon Dec 28 13:05:50 2015 berdrigue bongolo-beto
*/

int	check_str(char c)
{
  if (c == ' ' || c == '-' || c == '?' || c == '!' || c == '.')
      return 1;
  return 0;
}

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
	str[i] = str[i] - 32;
      if (check_str(str[i]))
	{
	  if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
	    str[i + 1] = str[i + 1] - 32;
	}
      i = i + 1;
    }
  return (str);
}
