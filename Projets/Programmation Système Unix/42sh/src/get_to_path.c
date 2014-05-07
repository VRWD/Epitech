/*
** get_to_path.c for get to path in /u/all/algrin_t/cu/rendu/c/minishell1
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Tue Dec 30 11:54:08 2008 thibaut algrin
** Last update Tue May 26 15:28:00 2009 remi prsien-
*/

#include "minishell.h"
#include "define.h"
#include "my_strcmp.h"
#include "get_to_path.h"
#include "my_str_in_tab.h"
#include "my_strcat.h"
#include "my_xmalloc.h"

char	**path_in_emergency(char *opt)
{
  char	**tab;

  tab = my_xmalloc_v((sizeof(*tab) * 8));
  tab[0] = "/usr/local/sbin";
  tab[0] = my_strcat2(tab[0], opt, '/');
  tab[1] = "/usr/local/bin";
  tab[1] = my_strcat2(tab[1], opt, '/');
  tab[2] = "/usr/sbin";
  tab[2] = my_strcat2(tab[2], opt, '/');
  tab[3] = "/usr/bin";
  tab[3] = my_strcat2(tab[3], opt, '/');
  tab[4] = "/sbin";
  tab[4] = my_strcat2(tab[4], opt, '/');
  tab[5] = "/bin";
  tab[5] = my_strcat2(tab[5], opt, '/');
  tab[6] = 0;
  return (tab);
}

char		**get_to_path(t_list *begin, char *opt)
{
  t_list	*save;
  char		**tab;

  tab = 0;
  save = begin;
  while (save != 0)
    {
      if (save->data != 0)
	{
	  if ((my_strncmp(PATH, save->data, 4) == 0))
	    {
	      tab = my_str_in_tab(save->data, opt);
	      return (tab);
	    }
	}
      save = save->next;
    }
  tab = path_in_emergency(opt);
  return (tab);
}
