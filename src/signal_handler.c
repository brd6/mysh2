/*
** signal_handler.c<PSU_2015_minishell2> for signal_handler in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Mar 21 00:24:16 2016 Berdrigue BONGOLO BETO
** Last update Sun Apr 10 16:39:51 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include <signal.h>
#include "my_printf.h"
#include "my.h"
#include "mysh.h"

void		sig_handler_sigint(int code)
{
  if (g_prompt != NULL)
    my_printf("\n%s", g_prompt);
}
