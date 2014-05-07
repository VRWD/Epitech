/*
** my_unalias.c for my_unalias in /u/all/algrin_t/cu/rendu/c/minishell2
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Mon Feb 23 18:19:07 2009 thibaut algrin
** Last update Fri May 22 09:44:16 2009 thibaut algrin
*/

#include "minishell.h"
#include "my_strcmp.h"
#include "my_putstr.h"
#include "my_exit.h"
#include "my_show_str_list.h"
#include "my_unalias.h"
#include "define.h"

int	my_del_elem_alias(char *buffer, t_list *begin)
{
  t_list	*new_elem;

  while (begin->next)
    {
      if (my_strncmp(begin->next->data, buffer, my_strlen(buffer) + 1) == 0)
	{
	  new_elem = begin->next;
	  begin->next = new_elem->next;
	  if (new_elem->next != 0)
	    new_elem->next->prev = begin;
	  new_elem->prev = NULL;
	  new_elem->next = NULL;
	  free(new_elem->data);
	  free(new_elem->data2);
	  free(new_elem);
	  return (0);
	}
      begin = begin->next;
    }
  my_putstr(UNSET_IM, 2);
  return (0);
}

void	my_unalias_all(t_struct *pile)
{
  my_free_list_alias(pile->my_alias);
  pile->my_alias = 0;
}

int		my_unalias(char *buffer, t_struct *pile)
{
  t_list	*save;
  t_list	*new_elem;

  save = pile->my_alias;
  if ((*buffer == 0) || (pile->my_alias == 0))
    {
      my_show_str_list2(pile->my_alias, pile->fd);
      return (0);
    }
  if ((buffer[0] != '*')
      && my_strncmp(pile->my_alias->data, buffer, my_strlen(buffer)) == 0)
    {
      new_elem = pile->my_alias->next;
      free(pile->my_alias->data);
      free(pile->my_alias->data2);
      free(pile->my_alias);
      pile->my_alias = new_elem;
      if (new_elem != NULL)
	pile->my_alias->prev = 0;
    }
  else if (buffer[0] != '*')
    my_del_elem_alias(buffer, pile->my_alias);
  if (buffer[0] == '*')
    my_unalias_all(pile);
  return (0);
}
