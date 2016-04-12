/*
** free_mysh.c for free_mysh in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Mar 21 00:08:58 2016 Berdrigue BONGOLO BETO
** Last update Tue Apr 12 17:01:48 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "mylist.h"
#include "mysh.h"

void		free_mysh(t_mysh *mysh)
{
  my_free_list(&mysh->my_env);
}
