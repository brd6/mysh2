/*
1;4002;0c** get_next_line.h for get_next_line.h in /home/bongol_b/rendu/get_next_line
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Dec 27 13:21:10 2015 berdrigue bongolo-beto
** Last update Sun Mar 20 00:38:24 2016 Berdrigue BONGOLO BETO
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE (2048)
# endif /* !READ_SIZE */

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char		*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
