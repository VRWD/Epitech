/*
** put_argv_in_tab.c for 42sh in /u/all/algrin_t/cu/rendu/c/42sh
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Thu May 21 15:43:26 2009 thibaut algrin
** Last update Sun Jun 21 19:13:28 2009 remi prsien-
*/

#include "minishell.h"
#include "my_xmalloc.h"
#include "my_putstr.h"
#include "put_argv_in_tab.h"
#include "put_av_in_tab.h"

int	check_sep(char *str, int i, int k)
{
  if (((str[i] == '|' && str[i - 1] == '|')
       || (str[i] == '&' && str[i - 1] == '&')
       || str[i] == ';') && k == 0)
    return (OK);
  return (NOT_OK);
}

int	check_pipe(char *str, int i)
{
  if ((str[i] == ' ') && ((str[i - 1] == '|' && str[i - 2] == '|')
			  || str[i - 1] == '&' || str[i - 1] == ';'))
    return (OK);
  return (NOT_OK);
}

char	**put_argv_in_tab(char *str, t_structs *str_tab)
{
  str_tab->i = 0;
  str_tab->n = 0;
  str_tab->k = 0;
  str_tab->tab = my_xmalloc_v(sizeof(str_tab->tab) * (my_strlen(str) + 1));
  str_tab->tab[str_tab->n] = my_xmalloc(sizeof(str_tab->tab[str_tab->n])
					* (my_strlen(str) + 1));
  while (str[str_tab->i] != '\0')
    {
      if ((str[str_tab->i] == '|' || str[str_tab->i] == '&'
	   || str[str_tab->i] == ';'))
	put_av_in_tab(str_tab, str);
      if (check_sep(str, str_tab->i, str_tab->k) == OK)
	str_tab->i++;
      if (check_pipe(str, str_tab->i) == OK)
	str_tab->i++;
      if (str[str_tab->i] != ';')
      str_tab->tab[str_tab->n][str_tab->k++] = str[str_tab->i++];
    }
  str_tab->tab[str_tab->n + 1] = NULL;
  return (str_tab->tab);
}
