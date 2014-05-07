/*
** aff_prrompt.c for aff_prompt in /u/all/algrin_t/cu/rendu/c/minishell2
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Mon Feb 23 12:31:08 2009 thibaut algrin
** Last update Sun Jun 21 21:46:34 2009 thibaut algrin
*/

#include <signal.h>
#include "minishell.h"
#include "main.h"
#include "aff_prompt.h"
#include "conf_prompt.h"
#include "my_putstr.h"
#include "my_strcpy.h"
#include "my_strcat.h"
#include "epur_str.h"
#include "inibiteur.h"
#include "check_dol_tild.h"
#include "conf.h"
#include "my_exit.h"
#include "my_check_alias.h"
#include "get_next_line.h"
#include "check_str.h"
#include "my_strcmp.h"
#include "aff_err.h"
#include "define.h"
#include "opt_liste_chaine.h"
#include "my_xmalloc.h"

void	init_variable(t_struct *pile)
{
  pile->ex_red = 0;
  pile->fd_exe = 1;
  pile->flag_exit = NOT_OK;
  pile->alias_i = OK;
  pile->e = OK;
  pile->seg[0] = NOT_OK;
  pile->seg[1] = NOT_OK;
  pile->in = 0;
  pile->flag_init = 0;
  pile->init = 0;
  pile->tmp = NULL;
  pile->fd_g = 0;
  pile->fd = 1;
  pile->red_d = 0;
  pile->red_dd = 0;
  pile->red_g = 0;
  pile->flag_ddg = 0;
  pile->flag_pipe = 0;
}

char	*gere_var(t_struct *pile, char *str)
{
  char	*al;
  char	*dol;
  char	*epur;
  char	*tmp;

  init_variable(pile);
  tmp = my_strdup(str);
  if (tmp != NULL)
    {
      epur = epur_str_hist(tmp, pile);
      epur = inibiteur(epur, pile);
      dol = check_dol(epur, pile);
      tmp = check_tild(dol, pile);
      al = my_check_alias(tmp, pile);
    }
  return (al);
}

void	aff_prompt(t_struct *pile)
{
  char	*str;
  char	*al;

  signal(SIGINT, ctr_c);
  pile->flag_exit = NOT_OK;
  while (my_strcmp(str = get_next_line(0), EXIT) != 0)
    {
      signal(SIGINT, ctr_c);
      str = epur_str(str);
      if ((str != NULL) && (str[0] != '|') && check_str(str, 0) == OK)
	{
	  al = gere_var(pile, str);
	  if ((al != NULL) && (al[0] != '\0'))
	    operation(al, pile);
	  free(al);
	}
      aff_inval_null(str);
      if (pile->conf != 0)
	par_prompt(pile->conf, pile);
      free(str);
      if (pile->flag_exit == OK)
	break;
    }
  if (pile->flag_exit != OK)
    my_exit("", pile, str, "");
}
