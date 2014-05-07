/*
** my_show_str_list.c for my show str list in /u/all/algrin_t/cu/rendu/c/minishell1
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Fri Dec 26 18:38:16 2008 thibaut algrin
** Last update Fri May 22 14:31:27 2009 thibaut algrin
*/

#include "minishell.h"
#include "my_putstr.h"

int     my_show_str_list(t_list *begin, t_struct *pile)
{
  while (begin != 0)
    {
      if (*begin->data != 0)
	{
	  my_putstr(begin->data, pile->fd);
	  my_putchar('\n', pile->fd);
	}
      begin = begin->next;
    }
  return (0);
}

void     my_show_str_list2(t_list *begin, int fd)
{
  if (begin != 0)
    {
      while (begin->prev)
	begin = begin->prev;
      while (begin->next != 0)
	{
	  if (*begin->data != 0)
	    {
	      my_putstr(begin->data, fd);
	      my_putchar('\t', fd);
	    }
	  if (*begin->data2 != 0)
	    my_putstr(begin->data2, fd);
	  my_putchar('\n', fd);
	  begin = begin->next;
	}
      my_putstr(begin->data, fd);
      my_putchar('\t', fd);
      my_putstr(begin->data2, fd);
      my_putchar('\n', fd);
      while (begin->prev)
	begin = begin->prev;
    }
}

int     my_show_str_list3(t_list *begin, int fd)
{
  t_list	*tmp;

  tmp = begin;
  if (tmp != 0)
    while (tmp->next)
      tmp = tmp->next;
  while (tmp != 0)
    {
      my_putstr(tmp->data, fd);
      my_putchar('\n', fd);
      tmp = tmp->prev;
    }
  return (0);
}
