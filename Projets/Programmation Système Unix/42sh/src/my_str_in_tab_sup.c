/*
** my_str_in_tab_sup.c for 42sh in /u/all/algrin_t/cu/rendu/c/42sh
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Tue May 19 12:40:06 2009 thibaut algrin
** Last update Fri Jun 19 16:19:44 2009 thibaut algrin
*/

#include "minishell.h"
#include "my_strcat.h"
#include "my_strcpy.h"

void	sup(char **tab, int n, char *opt)
{
  if (opt[0] == '/')
    {
      tab[n + 1] = my_strdup(opt);
      tab[n + 2] = 0;
    }
  else
    tab[n + 1] = NULL;
}

void	ex(char **tab, int n, char *tmp, int flag)
{
  if (flag == 1)
    {
      tab[n++] = my_strdup(tmp);
      tab[n] = 0;
    }
  else
    tab[n] = 0;
  free(tmp);
}
