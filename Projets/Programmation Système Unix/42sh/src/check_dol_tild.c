/*
** check_dol_tild.c for minishell2 in /u/all/algrin_t/cu/rendu/c/minishell2bis
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Thu Mar  5 10:17:16 2009 thibaut algrin
** Last update Sun Jun 21 16:01:08 2009 remi prsien-
*/

#include "minishell.h"
#include "define.h"
#include "my_xmalloc.h"
#include "my_putstr.h"
#include "my_strcat.h"
#include "opt_liste_chaine.h"
#include "check_dol_tild.h"

char	*check_dol_ext(char *str, int i)
{
  int	k;
  char	*val;

  k = 0;
  i++;
  val = my_xmalloc(sizeof(*val) * (my_strlen(str) + 2));
  while ((str[i] != ' ') && (str[i] != '\0')
	 && (str[i] != '/') && (str[i] != '\'') && (str[i] != '"'))
    val[k++] = str[i++];
  val[k] = '\0';
  return (val);
}

void	extrac_dol(t_struct *pile, t_var *w, char *str)
{
  char	*val;
  char	*tmp;

  if ((pile->init == 0) && (str[w->i] == '$') && (str[w->i - 1] != '\\'))
    {
      val = check_dol_ext(str, w->i);
      w->i = w->i + my_strlen(val) + 1;
      tmp = my_aff_param_list(pile->my_env, val);
      if (tmp == NULL)
	{
	  my_putstr(val, 1);
	  my_putstr(": Undefined variable.", 1);
	}
      w->opt = my_strcat3(w->opt, tmp);
      free(tmp);
      free(val);
      w->n = my_strlen(w->opt);
    }
}

char	*check_dol(char *str, t_struct *pile)
{
  t_var	w;

  w.n = 0;
  w.i = 0;
  w.opt = my_xmalloc(sizeof(w.opt)  * (my_strlen(str) + 5));
  while (str[w.i] != '\0')
    {
      extrac_dol(pile, &w, str);
      w.opt[w.n++] = str[w.i++];
    }
  w.opt[w.n] = '\0';
  free(str);
  return (w.opt);
}

void	extrac_tild(t_var *r, t_struct *pile, char *str)
{
  int	flag;
  char	*tmp;

  flag = 0;
  if ((str[r->i] == '\\') && (str[r->i + 1] != '>')
      && (str[r->i + 1] != '<') && (str[r->i + 1] != '*') && (pile->in == 1))
      r->i++;
  if ((pile->init == 0) && (str[r->i] == '~') && (str[r->i - 1] != '\\'))
    {
      r->i++;
      tmp = my_aff_param_list(pile->my_env, HOME);
      if (tmp == NULL)
	{
	  tmp = pile->home;
	  flag = 1;
	}
      r->opt = my_strcat3(r->opt, tmp);
      r->n = my_strlen(r->opt);
      if (flag == 0)
	free(tmp);
    }
}

char	*check_tild(char *str, t_struct *pile)
{
  int	flag;
  t_var	r;

  r.n = 0;
  r.i = 0;
  flag = 0;
  r.opt = my_xmalloc(sizeof(r.opt)  * (my_strlen(str) + 2));
  while (str[r.i] != '\0')
    {
      extrac_tild(&r, pile, str);
      r.opt[r.n++] = str[r.i++];
    }
  r.opt[r.n] = '\0';
  free(str);
  return (r.opt);
}
