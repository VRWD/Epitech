/*
** my_list_size.c for my list size in /u/all/algrin_t/cu/rendu/piscine/Jour_11
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Wed Oct 22 11:37:59 2008 thibaut algrin
** Last update Tue Jan 27 03:16:01 2009 thibaut algrin
*/

#include "minishell.h"

int	my_list_size(t_list *begin)
{
  int	j;

  j = 0;
  while (begin != 0)
    {
      begin = begin->next;
      j = j + 1;
    }
  return (j);
}
