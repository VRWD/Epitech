/*
** parseur_minishell.c for parseur_minishell in /u/all/algrin_t/cu/rendu/c/minishell2
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Mon Feb 23 12:30:33 2009 thibaut algrin
** Last update Sun Jun 21 21:42:10 2009 thibaut algrin
*/

#include "minishell.h"
#include "my_redi_double_as.h"
#include "my_env.h"
#include "my_exit.h"
#include "my_redi.h"
#include "my_redi_double.h"
#include "my_setenv.h"
#include "my_unsetenvbis.h"
#include "my_echo.h"
#include "my_alias.h"
#include "my_unalias.h"
#include "parseur_minishell.h"
#include "define.h"
#include "my_putstr.h"
#include "my_xmalloc.h"
#include "my_strcmp.h"
#include "opt_liste_chaine.h"
#include "my_exeve.h"
#include "my_hist.h"
#include "my_getpwd.h"

int	my_hist(char *opt, t_struct *pile);

int	my_cd(char *opt, t_struct *pile);

t_opers tab[] = {
  {"env", my_env},
  {EXIT, my_exit},
  {"<", my_redir_left},
  {">", my_redir_right},
  {">>", my_redir_right_double},
  {"<<", my_redi_left_double},
  {0, 0}
};

t_opers tab_more_opt[] = {
  {"history", my_hist},
  {"setenv", my_setenv},
  {"cd", my_cd},
  {"unsetenv", my_unsetenv},
  {"echo", my_echo},
  {"alias", my_alias},
  {"unalias", my_unalias},
  {"version", my_version},
  {0, 0}
};

int	my_version(char	*opt, t_struct *pile)
{
  opt = opt;
  pile = pile;
  my_putstr(SUJET, 1);
  my_putstr(VERSION, 1);
  my_putstr(DATE, 1);
  return (0);
}

int	parseur_minishell_opt(char *com, char *opt, t_struct *pile)
{
  char	*val;

  if (my_strcmp("pwd", com) == 0)
    {
      if (redi_opt(pile) == NOT_OK)
	return (0);
      gest_pipe(pile);
      val = my_aff_param_list(pile->my_env, "PWD");
      if (val != NULL)
	{
	  if (*val != 0)
	    my_putstr(val, pile->fd);
	  else if (pile->my_env != 0)
	    my_putstr("undefine", 1);
	  free(val);
	}
      else if ((pile->pwd != NULL) && (*pile->pwd != 0))
	my_putstr(pile->pwd, pile->fd);
      else
	my_putstr(my_getpwd(pile->pwd), 1);
      my_putchar('\n', pile->fd);
    }
  else
    my_execve(com, opt, pile);
  return (0);
}

int	ini_par(t_struct *pile, char *com, char *opt)
{
  if (pile->seg[1] == OK)
    pile->e = NOT_OK;
  if ((my_strcmp(com, EXIT) == 0) && (*opt == 0))
    {
      pile->flag_exit = OK;
      return (1);
    }
  if (pile->my_env != 0)
    while (pile->my_env->prev)
      pile->my_env = pile->my_env->prev;
  return (0);
}

int	parseur_minishell(char *com, char *opt, t_struct *pile, char *str)
{
  int   i;

  i = 0;
  if (ini_par(pile, com, opt) == 1)
    return (0);
  if (pile->my_alias != 0)
    while (pile->my_alias->prev)
      pile->my_alias = pile->my_alias->prev;
  while (tab[i].opers != 0)
    {
      if (my_strcmp(tab[i].opers, com) == 0)
	return (tab[i].f(opt, pile, str, com));
      i++;
    }
  i = 0;
  while (tab_more_opt[i].opers != 0)
    {
      if (my_strcmp(tab_more_opt[i].opers, com) == 0)
	return (tab_more_opt[i].f(opt, pile));
      i++;
    }
  parseur_minishell_opt(com, opt, pile);
  return (0);
}
