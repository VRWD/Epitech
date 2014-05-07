/*
** my_unsetenv.c for my_unsetenv in /u/all/algrin_t/cu/rendu/c/minishell1
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Mon Jan 19 17:11:59 2009 thibaut algrin
** Last update Mon Jun  1 12:50:41 2009 thibaut algrin
*/

#include <stdlib.h>
#include "minishell.h"
#include "my_strcmp.h"
#include "my_putstr.h"
#include "my_exit.h"
#include "my_xmalloc.h"
#include "my_unsetenvbis.h"
#include "define.h"

int	my_del_elem(char *buffer, t_list *begin)
{
  t_list	*new_elem;

  while (begin->next)
    {
      if (my_strcmp2(buffer, begin->next->data) == 0)
	{
	  new_elem = begin->next;
	  begin->next = new_elem->next;
	  if (new_elem->next != 0)
	    new_elem->next->prev = begin;
	  new_elem->prev = NULL;
	  new_elem->next = NULL;
	  free(new_elem->data);
	  free(new_elem);
	  return (0);
	}
      begin = begin->next;
    }
  my_putstr(UNSET_IM, 2);
  return (0);
}

int		my_unsetenvbis(char *buffer, t_struct *pile)
{
  int		p;
  t_list	*save;
  t_list	*new_elem;

  p = 0;
  save = pile->my_env;
  if (buffer[0] == '*')
    {
      my_free_list(pile->my_env);
      pile->my_env = 0;
      return (0);
    }
  if (my_strcmp2(buffer, pile->my_env->data) == 0)
    {
      new_elem = pile->my_env->next;
      free(pile->my_env->data);
      free(pile->my_env);
      pile->my_env = new_elem;
      if (new_elem != NULL)
	pile->my_env->prev = 0;
    }
  else
    my_del_elem(buffer, pile->my_env);
  return (0);
}

char	**my_str_towordtab(char *buffer, char c)
{
  int	i;
  int	n;
  int	k;
  char	**tab;

  n = 0;
  k = 0;
  i = 0;
  tab = my_xmalloc_v(sizeof(*tab) * (my_strlen(buffer) + 2));
  tab[0] = my_xmalloc_v(sizeof(*tab[0]) * (my_strlen(buffer) + 1));
  while (buffer[i] != '\0')
    {
      if (buffer[i] == c)
	{
	  i++;
	  tab[++n] = my_xmalloc_v(sizeof(*tab[0]) * (my_strlen(buffer) + 1));
	  k = 0;
	}
      tab[n][k++] = buffer[i++];
    }
  tab[n + 1] = 0;
  return (tab);
}

int		my_unsetenv(char *buffer, t_struct *pile)
{
  int	n;
  char	**tab;

  n = 0;
  tab = my_str_towordtab(buffer, ' ');
  if (pile->my_env == 0)
    return (0);
  while (tab[n] != 0)
    {
      my_unsetenvbis(tab[n], pile);
      free(tab[n]);
      n++;
    }
  free(tab);
  return (0);
}
