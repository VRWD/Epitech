/*
** my_str_in_tabbis.c for minishell2 in /u/all/algrin_t/cu/rendu/c/minishell2bis
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Thu Mar  5 09:11:09 2009 thibaut algrin
** Last update Sat Jun 20 11:11:39 2009 thibaut algrin
*/

#include "minishell.h"
#include "my_xmalloc.h"
#include "my_putstr.h"
#include "my_strcat.h"
#include "my_str_in_tab_sup.h"
#include "my_strcpy.h"
#include "my_strcmp.h"

void	annexe(char *str, char **tab, int i, char *opt)
{
  int	k;
  char	*tmp;
  int	n;

  k = 0;
  n = 0;
  tmp = my_xmalloc(sizeof(*tmp) * (my_strlen(str) + 2));
  while (str[i] != '\0')
    {
      if (str[i] == ':')
	{
	  tmp[k] = '/';
	  tab[n] = my_strcat(tmp, opt);
	  free(tmp);
	  n++;
	  tmp = my_xmalloc(sizeof(*tmp) * (my_strlen(str) + 2));
	  i++;
	  k = 0;
	}
      tmp[k++] = str[i++];
    }
  tmp[k] = '/';
  tab[n] = my_strcat(tmp, opt);
  free(tmp);
  sup(tab, n, opt);
}

char	**my_str_in_tab(char *str, char *opt)
{
  int	i;
  char	**tab;
  int	n;

  i = 0;
  n = 0;
  tab = my_xmalloc_v(sizeof(*tab) * (my_strlen(str) + 3));
  while (str[i] != '=' && str[i] != '\0')
    i++;
  i++;
  annexe(str, tab, i, opt);
  return (tab);
}

void	annexe2(char *str, int n, char **tab)
{
  int	i;
  int	flag;
  char	*tmp;
  int	k;

  i = 0;
  k = 0;
  flag = 0;
  tmp = my_xmalloc(sizeof(*tmp) * (my_strlen(str) + 2));
  while (str[i] != '\0')
    {
      if ((str[i] == ' ') && (str[i + 1] != '\0'))
	{
	  tmp[k] = '\0';
	  tab[n++] = my_strdup(tmp);
	  free(tmp);
	  tmp = my_xmalloc(sizeof(*tmp) * (my_strlen(str) + 2));
	  i++;
	  k = 0;
	}
      flag = 1;
      tmp[k++] = str[i++];
    }
  ex(tab, n, tmp, flag);
}

char	**my_str_in_tab2(char *opt, char *tmp)
{
  int	i;
  char	**tab;
  int	n;
  int	k;

  i = 0;
  k = 0;
  n = 1;
  if ((*opt == 0) && (my_strcmp("ls", tmp) == 0) &&
      (my_strcmp("make", tmp) == 0))
    opt = "./";
  tab = my_xmalloc_v(sizeof(*tab) * (my_strlen(tmp) + 2));
  tab[0] = my_xmalloc(sizeof(*tab[0]) * (my_strlen(tmp) + 1));
  tab[0] = my_strcpy(tab[0], tmp);
  if (opt != 0)
    annexe2(opt, n, tab);
  return (tab);
}
