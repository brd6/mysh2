/*
** file.h for file in /home/bongol_b/Epitech-rendu/libmy/include
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Mar 14 00:39:01 2016 Berdrigue BONGOLO BETO
** Last update Mon Mar 14 01:23:18 2016 Berdrigue BONGOLO BETO
*/

#ifndef FILE_H_
# define FILE_H_

typedef struct		s_file
{
  void			*data;
  struct s_file		*next;
  struct s_file		*queue;
  struct s_file		*head;
}			t_file;

t_file		init_file();
int		file_is_empty(t_file *file);
void		*file_head(t_file *file);
void		file_free(t_file *file);
int		file_enqueue(t_file *file, void *data);
void		*file_dequeue(t_file *file);
void		*file_queue(t_file *file);
#endif /* !FILE_H_ */
