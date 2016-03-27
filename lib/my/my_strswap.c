/*
** my_strswap.c for my_strswap in /home/bongol_b/Piscine_C_workshoplib/lib/my
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Oct 20 13:26:34 2015 berdrigue bongolo-beto
** Last update Mon Dec 28 13:22:22 2015 berdrigue bongolo-beto
*/

void	my_strswap(char **str1_ptr, char **str2_ptr)
{
  char	*tmp;

  tmp = *str1_ptr;
  *str1_ptr = *str2_ptr;
  *str2_ptr = tmp;
}
