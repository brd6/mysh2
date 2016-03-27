/*
** my_strncat.c for my_strncat in /home/bongol_b/rendu/Piscine_C_J07
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Wed Oct  7 00:14:02 2015 berdrigue bongolo-beto
** Last update Mon Dec 28 13:10:28 2015 berdrigue bongolo-beto
*/

int	my_strncat_len(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}

char	*my_strncat(char *dest, char *src, int nb)
{
  int	dest_len;
  int	i;

  dest_len = my_strncat_len(dest);
  i = 0;
  while (src[i] && i < nb)
    {
      dest[i + dest_len] = src[i];
      i = i + 1;
    }
  dest[i + dest_len] = 0;
  return (dest);
}
