/*
** conf_prompt.c for 42sh in /u/all/algrin_t/cu/rendu/c/42sh
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Tue May 19 12:44:56 2009 thibaut algrin
** Last update Sun Jun 21 20:56:56 2009 thibaut algrin
*/

#include "minishell.h"
#include "conf_prompt.h"
#include "define.h"
#include "xfonction.h"
#include "opt_liste_chaine.h"
#include "my_putstr.h"
#include "conf.h"

void	opt_p(char c, t_struct *pile)
{
  char	*tmp;

  if (c == 'p')
    {
      tmp = my_aff_param_list(pile->my_env, PWD);
      if (tmp != NULL)
	{
	  aff_home(tmp, pile);
	  free(tmp);
	}
      else
	my_putstr(UNKNOW, 1);
    }
}

void	extr_com_conf(char *str, char *com, char *opt)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while ((str[i] != ' ') && (str[i] != '\0'))
    com[j++] = str[i++];
  com[j] = '\0';
  i++;
  j = 0;
  while (str[i] != '\0')
    opt[j++] = str[i++];
  opt[j] = '\0';
}

void	par_prompt(char *tmp, t_struct *pile)
{
  static t_struct *tmp_p;
  int	i;

  i = 0;
  if (pile != NULL)
    {
      tmp_p = pile;
      while ((tmp[i] != ' ') && (tmp[i] != '\0'))
	i++;
      while (tmp[i++] != '\0')
	{
	  if (tmp[i] == '%')
	    {
	      opt_prompt(tmp[i + 1], pile);
	      i++;
	    }
	  else if (tmp[i] != ' ')
	    my_putchar(tmp[i], 1);
	}
    }
  else
    {
      my_putstr("\b\b  \b\b\n", 1);
      par_prompt(tmp_p->conf, tmp_p);
    }
}

void	ctr_c(int k)
{
  k = k;
  par_prompt(NULL, NULL);
}

void	file_conf(char *str, int fd, t_struct *pile)
{
  if (str != NULL)
    free(str);
  my_xclose(fd);
  pile->host = NULL;
}
