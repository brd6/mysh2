/*
** env_util.c for env_util in /home/bongol_b/rendu/PSU_2015_minishell1
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Jan  8 02:28:31 2016 Berdrigue BONGOLO BETO
** Last update Tue Mar 29 00:27:03 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"
#include "parser.h"

char		*get_env_key(char *env_data)
{
  char		*key;
  int		i;

  if ((key = malloc(sizeof(*key) * (my_strlen(env_data) + 1))) == NULL)
    exit_on_error("Malloc error\n");
  i = 0;
  while (env_data[i] && env_data[i] != '=')
    {
      key[i] = env_data[i];
      i++;
    }
  key[i] = 0;
  return (key);
}

char		*get_env_value(char *env_data)
{
  char		*value;
  int		i;
  int		j;

  if ((value = malloc(sizeof(*value) * (my_strlen(env_data) + 1))) == NULL)
    exit_on_error("Malloc error\n");
  i = 0;
  j = 0;
  while (env_data[i] && env_data[i] != '=')
    i++;
  i++;
  while (env_data[i])
    value[j++] = env_data[i++];
  value[j] = 0;
  return (value);
}

char		*key_to_value(t_list *env, char *key)
{
  t_list	*curr;

  curr = env;
  while (curr != NULL)
    {
      if (my_strcmp(get_env_key(curr->data), key) == 0)
	return (get_env_value(curr->data));
      curr = curr->next;
    }
  return (NULL);
}

char		**env_list_to_array(t_list *my_env)
{
  char		**tab;
  int		j;
  char		*s;

  if ((tab = malloc(sizeof(*tab) * (my_list_size(my_env) + 2))) == NULL)
    exit_on_error("Malloc error\n");
  j = 0;
  while (my_env)
    {
      s = my_env->data;
      tab[j] = my_strdup(s);
      my_env = my_env->next;
      j = j + 1;
    }
  tab[j] = 0;
  return (tab);
}
