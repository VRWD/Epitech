/*
** my_alias.c for my_alias in /u/all/algrin_t/cu/rendu/c/minishell2bis
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Fri Feb  6 17:59:11 2009 thibaut algrin
** Last update Sun May 24 17:58:45 2009 remi prsien-
*/

#include "minishell.h"
#include "my_xmalloc.h"
#include "my_putstr.h"
#include "my_strcpy.h"
#include "my_strcmp.h"
#include "my_show_str_list.h"

void		add_elem_to_liste2(char *arg, char *arg2, t_list **my_env)
{
  t_list	*new;

  new = my_xmalloc_v(sizeof(*new));
  if (arg != 0)
    {
      new->data = my_xmalloc(sizeof(*new->data) * (my_strlen(arg) + 1));
      new->data = my_strcpy(new->data, arg);
      new->data2 = my_xmalloc(sizeof(*new->data2) * (my_strlen(arg2) + 1));
      new->data2 = my_strcpy(new->data2, arg2);
    }
  new->next = 0;
  new->prev = *my_env;
  if (*my_env)
    (*my_env)->next = new;
  *my_env = new;
}

int	change_alias(t_struct *pile, char *com, char *val, int flag)
{
  int	k;

  if (my_strcmp(pile->my_alias->data, com) == 0)
    {
      k = sizeof(pile->my_alias->data2) * (my_strlen(val) + 1);
      free(pile->my_alias->data2);
      pile->my_alias->data2 = my_xmalloc(k);
      pile->my_alias->data2 = my_strcpy(pile->my_alias->data2, val);
      flag = 1;
    }
  return (flag);
}

int		my_alias_compare(t_struct *pile, char *val, char *com)
{
  t_list	*save;
  int		flag;

  flag = 0;
  save = pile->my_alias;
  while (pile->my_alias->prev)
    pile->my_alias = pile->my_alias->prev;
  while (pile->my_alias->next != 0)
    {
      flag = change_alias(pile, com, val, flag);
      pile->my_alias = pile->my_alias->next;
    }
  flag = change_alias(pile, com, val, flag);
  return (flag);
}

void	my_alias_search(char *opt, char *com, t_struct *pile, int i)
{
  char	*val;
  int	flag;
  int	j;

  j = 0;
  flag = 0;
  val = my_xmalloc(sizeof(*val) * (my_strlen(opt) + 2));
  while (opt[i] != '\0')
    val[j++] = opt[i++];
  val[j] = '\0';
  if (pile->my_alias)
    flag = my_alias_compare(pile, val, com);
  if (flag == 0)
    add_elem_to_liste2(com, val , &pile->my_alias);
  free(val);
}

int	my_alias(char *opt, t_struct *pile)
{
  char	*com;
  int	i;
  int	k;
  int	flag;
  int	j;

  i = 0;
  j = 0;
  k = 0;
  flag = 0;
  if (*opt == 0)
    my_show_str_list2(pile->my_alias, 1);
  else
    {
      com = my_xmalloc(sizeof(*com) * (my_strlen(opt) + 1));
      while ((opt[i] != ' ') && (opt[i] != '\0'))
	com[k++] = opt[i++];
      com[k] = '\0';
      i++;
      my_alias_search(opt, com, pile, i);
      free(com);
    }
  return (0);
}
