/*
** conf.c for 42sh in /u/all/algrin_t/cu/rendu/c/42sh
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Mon Apr 13 11:16:54 2009 thibaut algrin
** Last update Sun Jun 21 20:15:16 2009 thibaut algrin
*/

#include <signal.h>
#include <fcntl.h>
#include "minishell.h"
#include "conf_prompt.h"
#include "conf.h"
#include "my_putstr.h"
#include "xfonction.h"
#include "my_strcpy.h"
#include "my_strcmp.h"
#include "check_dol_tild.h"
#include "get_next_line.h"
#include "epur_str.h"
#include "my_xmalloc.h"
#include "opt_liste_chaine.h"
#include "define.h"
#include "parseur_minishell.h"

t_tab_pro	promt_tab[] = {
  {'h', HOST, LOCALHOST},
  {'p', PWD, UNKNOW},
  {'n', USER, USER_C},
  {0, 0, 0}
};

void	opt_prompt(char c, t_struct *pile)
{
  char	*tmp;
  int	i;

  i = 0;
  while (promt_tab[i].name != 0)
    {
      if ((c != 'p') && (promt_tab[i].name == c))
	{
	  tmp = my_aff_param_list(pile->my_env, promt_tab[i].res);
	  if (tmp != 0)
	    my_putstr_to_c(tmp, '.', 1);
	  else
	    my_putstr(promt_tab[i].remp, 1);
	  free(tmp);
	}
      i++;
    }
  opt_p(c, pile);
}

void	aff_home(char *tmp2, t_struct *pile)
{
  char	*home;

  home = my_aff_param_list(pile->my_env, HOME);
  if ((home != 0) && (my_strncmp(tmp2, home, my_strlen(home)) == 0))
    {
      my_putchar('~', 1);
      my_putstr2(tmp2, my_strlen(home), 1);
    }
  else if (home != 0)
    my_putstr(tmp2, 1);
  else
    my_putstr(UNKNOW, 1);
  free(home);
}

void	conf_all(char *tmp, t_struct *pile)
{
  char	*dol;
  char	*com;
  char	*opt;
  char	*t;

  if (tmp[0] != '\0')
    {
      dol = check_dol(tmp, pile);
      t = check_tild(dol, pile);
      com = my_xmalloc(sizeof(*com) * (my_strlen(t) + 2));
      opt = my_xmalloc(sizeof(*opt) * (my_strlen(t) + 2));
      extr_com_conf(t, com, opt);
      parseur_minishell(com, opt, pile, tmp);
      free(t);
      free(com);
      free(opt);
    }
  else
    free(tmp);
}

int	no_file(int fd, t_struct *pile)
{
  if (fd == -1)
    {
      my_putstr("Warning: You haven't a file for you configuration\n", 2);
      pile->conf = my_strdup("promt >$");
      par_prompt(pile->conf, pile);
      return (-1);
    }
  return (0);
}

int	fichier_conf(t_struct *pile)
{
  char	*str;
  char	*tmp;
  int	fd;

  if (((fd = open(MYCONF, O_RDONLY)) == -1) && (no_file(fd, pile) == -1))
    return (0);
  str = NULL;
  while ((str = get_next_line(fd)))
    {
      tmp = epur_str(str);
      if ((tmp[0] != '/') && (tmp[0] != '*')
	  && (my_strncmp(tmp, PROM, my_strlen(PROM)) != 0))
	conf_all(tmp, pile);
      else if (my_strncmp(tmp, PROM, my_strlen(PROM)) == 0)
	{
	  pile->conf = my_strdup(tmp);
	  par_prompt(tmp, pile);
	  free(tmp);
	}
      else
	free(tmp);
    }
  file_conf(str, fd, pile);
  return (0);
}
