/*
** my_hist.c for 42sh in /u/all/algrin_t/cu/public/42sh
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Sun Jun 21 19:27:20 2009 thibaut algrin
** Last update Sun Jun 21 19:51:57 2009 thibaut algrin
*/

#include "minishell.h"
#include "my_exit.h"
#include "my_strcmp.h"
#include "my_putstr.h"

int	my_hist(char *opt, t_struct *pile)
{
  int		i;
  t_list	*save;

  if (my_strcmp("-c", opt) == 0)
    {
      my_free_list(pile->hist);
      pile->hist = 0;
    }
  else
    {
      i = 0;
      save = pile->hist;
      while (save->prev)
	save = save->prev;
      while (save)
	{
	  my_put_nbr(i, pile->fd);
	  my_putstr(": ", pile->fd);
	  my_putstr(save->data, pile->fd);
	  my_putstr("\n", pile->fd);
	  save = save->next;
	  i++;
	}
    }
  return (0);
}
