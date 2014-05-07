/*
** my_exit.c for my exit in /u/all/algrin_t/cu/rendu/c/minishell1
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Fri Dec 26 18:38:38 2008 thibaut algrin
** Last update Wed May 27 17:03:08 2009 thibaut algrin
*/

#include <fcntl.h>
#include <stdlib.h>
#include "minishell.h"
#include "my_putstr.h"

int		my_free_list(t_list *begin)
{
  int		flag;
  t_list	*new;

  if (begin != 0)
    while (begin->prev)
      begin = begin->prev;
  while (begin != 0)
    {
      flag = 1;
      new = begin;
      if (begin->data != 0)
	free(new->data);
      begin = begin->next;
      free(new->prev);
    }
  if (flag == 1)
    free(new);
  return (0);
}

int		my_free_list_alias(t_list *begin)
{
  int		flag;
  t_list	*new;

  if (begin != 0)
    while (begin->prev)
      begin = begin->prev;
  while (begin != 0)
    {
      flag = 1;
      new = begin;
      if (begin->data != 0)
	free(new->data);
      if (begin->data2 != 0)
	free(new->data2);
      begin = begin->next;
      free(new->prev);
    }
  if (flag == 1)
    free(new);
  return (0);
}

void	my_exit_m(char *com, char *opt)
{
  if (*com != 0)
    free(com);
  if (*opt != 0)
    free(opt);
  my_putstr("\n", 1);
}

int     my_exit(char *opt, t_struct *pile, char *str, char *com)
{
  if (*opt != 0)
    {
      pile->flag_exit = NOT_OK;
      my_putstr("Missing file name\n", 2);
      return (0);
    }
  if (pile->home != 0)
    free(pile->home);
  if (pile->conf != 0)
    free(pile->conf);
  if (pile->hist != 0)
    my_free_list(pile->hist);
  if (pile->my_env != 0)
    my_free_list(pile->my_env);
  if (pile->save_cd != 0)
    my_free_list(pile->save_cd);
 if (pile->my_alias != 0)
    my_free_list_alias(pile->my_alias);
  if (pile->pwd != 0)
    free(pile->pwd);
  if (str != 0)
    free(str);
  my_exit_m(com, opt);
  return (0);
}
