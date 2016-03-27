/*
** signal_handler.c<PSU_2015_minishell2> for signal_handler in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Mar 21 00:24:16 2016 Berdrigue BONGOLO BETO
** Last update Mon Mar 21 00:38:41 2016 Berdrigue BONGOLO BETO
*/

#include <signal.h>
#include "my_printf.h"
#include "mysh.h"

void		sig_handler_sigint(int code)
{
  my_printf("\n%s", g_prompt);
}
