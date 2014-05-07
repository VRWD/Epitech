/*
** epur_str.c for epur_str in /u/all/algrin_t/cu/rendu/c/minishell1
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Tue Jan 27 16:39:43 2009 thibaut algrin
** Last update Sun Jun 21 19:55:56 2009 thibaut algrin
*/

#include "minishell.h"
#include "my_putstr.h"
#include "my_xmalloc.h"
#include "opt_liste_chaine.h"

char	*epur_str(char *str)
{
  char	*tmp;
  int	i;
  int	k;

  i = 0;
  k = 0;
  tmp = my_xmalloc(sizeof(*tmp) * (my_strlen(str) + 1));
  while ((str[i] == ' ') || (str[i] == '\t'))
    i++;
  while (str[i] != '\0')
    {
      tmp[k++] = str[i++];
      while ((str[i] == ' ') || (str[i] == '\t'))
	i++;
      if (((str[i - 1] == ' ') || (str[i - 1] == '\t')) && (str[i] != '\0'))
	{
	  tmp[k] = ' ';
	  k++;
	}
    }
  tmp[k] = '\0';
  free(str);
  return (tmp);
}

char	*epur_str_hist(char *str, t_struct *pile)
{
  char	*tmp;
  int	i;
  int	k;

  i = 0;
  k = 0;
  tmp = my_xmalloc(sizeof(*tmp) * (my_strlen(str) + 3));
  while ((str[i] == ' ') || (str[i] == '\t'))
    i++;
  while (str[i] != '\0')
    {
      tmp[k++] = str[i++];
      while ((str[i] == ' ') || (str[i] == '\t'))
	i++;
      if (((str[i - 1] == ' ') || (str[i - 1] == '\t')) && (str[i] != '\0'))
	{
	  tmp[k] = ' ';
	  k++;
	}
    }
  tmp[k] = '\0';
  add_elem_to_liste(tmp, &pile->hist);
  free(str);
  return (tmp);
}
