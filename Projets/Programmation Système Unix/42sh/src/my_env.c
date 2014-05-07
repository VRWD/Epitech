/*
** my_env.c for my_env in /u/all/algrin_t/cu/rendu/c/minishell1bis
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Mon Jan 19 17:40:24 2009 thibaut algrin
** Last update Sun Jun 21 22:26:42 2009 thibaut algrin
*/

#include "minishell.h"
#include "extraction_com_opt.h"
#include "redirection.h"
#include "my_putstr.h"
#include "my_show_str_list.h"
#include "parseur_minishell.h"
#include "my_exeve.h"

void	my_env_opt(char *opt, t_struct *pile, char *str)
{
  char	*com_tmp;
  char	*opt_tmp;

  com_tmp = extraction_comande(opt, com_tmp, pile);
  opt_tmp = extraction_option(opt, opt_tmp, pile);
  parseur_minishell(com_tmp, opt_tmp, pile, str);
  free(com_tmp);
  free(opt_tmp);
}

int	redi_opt(t_struct *pile)
{
  if (pile->red_d == 1)
    {
      pile->ex_red = 1;
      pile->i = 1;
      if (redirection_droite(pile, pile->tmp, pile->pos) == NOT_OK)
	return (NOT_OK);
    }
  else if (pile->red_g == 1)
    {
      pile->i = 1;
      if (redirection_gauche(pile, pile->tmp, pile->pos) == NOT_OK)
	return (NOT_OK);
    }
  else if (pile->red_dd == 1)
    {
      pile->i = 1;
      if (redirection_double_droite(pile, pile->tmp, pile->pos) == NOT_OK)
	return (NOT_OK);
    }
  return (OK);
}

int	my_env(char *opt, t_struct *pile, char *str, char *com)
{
  int	k;

  gest_pipe(pile);
  k = my_strlen(com);
  if (pile->my_env != 0)
    while (pile->my_env->prev)
      pile->my_env = pile->my_env->prev;
  if (redi_opt(pile) == NOT_OK)
    return (0);
  if (*opt == 0)
    my_show_str_list(pile->my_env, pile);
  else if (pile->fd == 1)
    my_env_opt(opt, pile, str);
  if (pile->my_env != 0)
    while (pile->my_env->prev)
      pile->my_env = pile->my_env->prev;
   return (0);
}
