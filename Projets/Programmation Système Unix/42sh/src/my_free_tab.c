/*
** my_free_tab.c for my_free_tab in /u/all/algrin_t/cu/rendu/c/minishell1
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Thu Jan  8 12:17:03 2009 thibaut algrin
** Last update Mon Jun  1 15:32:08 2009 thibaut algrin
*/

#include "minishell.h"

void    my_free_tab(char **tab)
{
  int   n;

  n = 0;
  while (tab[n] != 0)
    {
      if (tab[n] != 0)
	free(tab[n]);
      n++;
    }
}
