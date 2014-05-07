/*
** inibiteur.c for 42sh in /u/all/algrin_t/cu/rendu/c/42sh
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Thu Apr 30 09:40:33 2009 thibaut algrin
** Last update Tue May 26 16:57:14 2009 remi prsien-
*/

#include "minishell.h"
#include "my_xmalloc.h"
#include "my_putstr.h"
#include "my_strcat.h"
#include "inibiteur.h"

void	ex_d_q(t_var1 *as, char *str)
{
  char	*tmp;

  tmp = NULL;
  as->j = 0;
  as->i++;
  tmp = my_xmalloc(sizeof(*tmp) * (my_strlen(str) + 1));
  while ((str[as->i] != '"') && (str[as->i] != '\0'))
    tmp[as->j++] = str[as->i++];
  tmp[as->j] = '\0';
  as->res = my_strcat3(as->res, tmp);
  as->k += my_strlen(tmp);
  as->i++;
  free(tmp);
}

void	ex_s_q(t_struct *pile, t_var1 *as, char *str)
{
  char	*tmp;

  tmp = NULL;
  if ((str[as->i + 1] == '"') && (str[as->i + 2] != '\0'))
    pile->in = 1;
  pile->init ^= 1;
  as->j = 0;
  as->i++;
  tmp = my_xmalloc(sizeof(*tmp) * (my_strlen(str) + 1));
  while ((str[as->i] != '\'') && (str[as->i] != '\0'))
    tmp[as->j++] = str[as->i++];
  tmp[as->j] = '\0';
  as->res = my_strcat3(as->res, tmp);
  as->k += my_strlen(tmp);
  as->i++;
  free(tmp);
}

char		*inibiteur(char *str, t_struct *pile)
{
  t_var1	as;

  as.i = 0;
  as.k = 0;
  as.res = my_xmalloc(sizeof(*as.res) * (my_strlen(str) + 1));
  while ((str[as.i] != '\0') && (str[as.i] != ' '))
    as.res[as.k++] = str[as.i++];
  as.res[as.k++] = str[as.i++];
  while (str[as.i] != '\0')
    {
      if ((str[as.i] == '"') && (str[as.i + 1] != '>')
	  && (str[as.i + 1] != '<') && (str[as.i + 1] != '\0'))
	ex_d_q(&as, str);
      else if ((str[as.i] == '\'') && (str[as.i - 1] != '\\'))
	ex_s_q(pile, &as, str);
      else
	as.res[as.k++] = str[as.i++];
    }
  free(str);
  return (as.res);
}
