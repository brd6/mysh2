/*
** my_check_uniq_char.c for my_check_uniq_char in /home/bongol_b/rendu/Piscine_C_bistromathique
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Oct 30 17:25:30 2015 berdrigue bongolo-beto
** Last update Fri Oct 30 17:25:41 2015 berdrigue bongolo-beto
*/

int	my_check_uniq_char(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i])
    {
      j = 0;
      while (str[j])
	{
	  if (j != i && str[j] == str[i])
	    return (0);
	  j = j + 1;
	}
      i = i + 1;
    }
  return (1);
}
