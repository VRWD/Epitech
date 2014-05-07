/*
** my_check_alias.c for my_check_alias in /u/all/algrin_t/cu/rendu/c/minishell2
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Mon Feb 23 18:20:44 2009 thibaut algrin
** Last update Sun May 24 18:00:52 2009 remi prsien-
*/

#include "minishell.h"
#include "my_xmalloc.h"
#include "my_putstr.h"
#include "my_strcmp.h"
#include "my_strcpy.h"
#include "my_strcat.h"
#include "define.h"

char	*my_alias_copy(char *str, char *com)
{
  int	i;
  int	j;
  char	*tmp;
  char	*opt;

  i = 0;
  j = 0;
  tmp = my_xmalloc(sizeof(*tmp) * (my_strlen(str) + 1));
  tmp = my_strcpy(tmp, str);
  opt = my_xmalloc(sizeof(*com) * (my_strlen(str) + 1));
  while ((tmp[i] != '\0') && (tmp[i] != ' '))
    com[j++] = tmp[i++];
  com[j] = '\0';
  j = 0;
  if (tmp[i] == '\0')
    {
      free(tmp);
      free(opt);
      return (NULL);
    }
  while ((tmp[i] != '\0'))
    opt[j++] = tmp[i++];
  opt[j] = '\0';
  free(tmp);
  return (opt);
}

char	*my_check_list(t_struct *pile, char *com, char *opt)
{
  int		p;
  t_list	*save;
  char		*tmp;

  p = 0;
  save = pile->my_alias;
  tmp = NULL;
  while (save != 0)
    {
      if (my_strcmp(save->data, com) == 0)
	{
	  tmp = my_strcat(save->data2, opt);
	  com = tmp;
	  save = pile->my_alias;
	}
      save = save->next;
      if (p == 1000)
	{
	  pile->alias_i = NOT_OK;
	  my_putstr(ALIAS_LOOP, 2);
	  return (NULL);
	}
      p++;
    }
  return (tmp);
}

char	*my_check_alias(char *str, t_struct *pile)
{
  char	*com;
  char	*opt;

  com = my_xmalloc(sizeof(*com) * my_strlen(str) + 1);
  opt = my_alias_copy(str, com);
  free(str);
  if (pile->my_alias != 0)
    while (pile->my_alias->prev)
      pile->my_alias = pile->my_alias->prev;
  if ((pile->my_alias != 0) && (*pile->my_alias->data != 0))
    if ((str = my_check_list(pile, com, opt)))
      {
	free(opt);
	free(com);
	return (str);
      }
  if (pile->alias_i == OK)
    {
      str = my_strcat(com, opt);
      free(opt);
      free(com);
    }
  return (str);
}
