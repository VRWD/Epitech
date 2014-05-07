/*
** my_redi_double_as.c for 42sh in /u/all/algrin_t/cu/rendu/c/42sh
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Tue May 19 12:41:37 2009 thibaut algrin
** Last update Fri Jun 19 13:16:56 2009 remi prsien-
*/

#include "minishell.h"
#include "my_redi_double_as.h"
#include "my_xmalloc.h"
#include "define.h"
#include "my_exit.h"
#include "my_putstr.h"
#include "opt_liste_chaine.h"
#include "my_free_tab.h"
#include "my_list_size.h"
#include "get_to_path.h"
#include "my_str_in_tab.h"
#include "my_strcmp.h"
#include "get_next_line.h"
#include "my_exeve.h"
#include "my_exeve_gauche.h"
#include "my_redi_double.h"
#include "aff_key.h"

void	my_extrc_left(char *tmp, char *opt, char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] == '<')
    i++;
  i += 1;
  while (str[i] != ' ' && (str[i] != '\0'))
    i++;
  i++;
  while (str[i] != ' ' && (str[i] != '\0'))
    tmp[j++] = str[i++];
  tmp[j] = '\0';
  j = 0;
  while (str[i] != '\0')
    opt[j++] = str[i++];
  opt[j] = '\0';
}

void	my_free_ex(char **my_env_tab, char **path, char **act)
{
  my_free_tab(my_env_tab);
  my_free_tab(path);
  my_free_tab(act);
  free(act);
  free(my_env_tab);
  free(path);
}

void	exe_left(t_struct *pile, char *str)
{
  char  **act;
  char  **path;
  char	**my_env_tab;
  char	*tmp;
  char	*opt;
  int	i;
  int	j;
  int   k;

  k = my_list_size(pile->my_env) + 2;
  j = 0;
  i = 0;
  tmp = my_xmalloc(sizeof(*tmp) * (my_strlen(str) + 1));
  opt = my_xmalloc(sizeof(*opt) * (my_strlen(str) + 1));
  my_env_tab = my_xmalloc_v(sizeof(*my_env_tab) * k);
  my_env_tab = my_list_in_tab(pile->my_env, my_env_tab);
  my_extrc_left(tmp, opt, str);
  path = get_to_path(pile->my_env, tmp);
  act = my_str_in_tab2(opt, tmp);
  check_com_gauche(path, act, pile, my_env_tab);
  my_free_ex(my_env_tab, path, act);
  free(opt);
  free(tmp);
}

void	my_exe_left(t_struct *pile, char *str)
{
  if (pile->my_redir_g != 0)
    {
      while (pile->my_redir_g->next)
	{
	  exe_left(pile, str);
	  pile->my_redir_g = pile->my_redir_g->next;
	}
      exe_left(pile, str);
    }
}

int	my_redi_left_double(char *opt, t_struct *pile,
			    char *str, __attribute__((unused))char *com)
{
  char	*stop;
  int	i;
  char	*arg;

  i = 0;
  pile->my_redir_g = 0;
  if ((stop = extra_stop(opt)) == NULL)
    return (0);
  aff_key(stop);
  while (my_strcmp(stop, arg = get_next_line(0)) != 0)
    {
      if ((arg != NULL) && (arg[0] != '\0'))
	add_elem_to_liste(arg, &pile->my_redir_g);
      free(arg);
      my_putstr(SYM_RED_G, 1);
    }
  free(stop);
  free(arg);
  if (pile->my_redir_g != 0)
    while (pile->my_redir_g->prev)
      pile->my_redir_g = pile->my_redir_g->prev;
  my_exe_left(pile, str);
  if (pile->my_redir_g != 0)
    my_free_list(pile->my_redir_g);
  return (0);
}
