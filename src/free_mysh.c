/*
** free_mysh.c for free_mysh in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Mar 21 00:08:58 2016 Berdrigue BONGOLO BETO
** Last update Sun Mar 27 03:13:46 2016 Berdrigue BONGOLO BETO
*/

#include "mylist.h"
#include "mysh.h"

void		free_mysh(t_mysh *mysh)
{
  my_free_list(&mysh->my_env);
  free(g_prompt);
}
