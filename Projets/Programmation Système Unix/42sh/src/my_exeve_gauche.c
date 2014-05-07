/*
** my_exeve_gauche.c for my_exeve_gauche in /u/all/algrin_t/cu/rendu/c/minishell2
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Wed Feb 25 19:58:44 2009 thibaut algrin
** Last update Sun Jun 21 22:15:35 2009 thibaut algrin
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell.h"
#include "my_xmalloc.h"
#include "epur_str.h"
#include "xfonction.h"
#include "my_list_size.h"
#include "my_putstr.h"
#include "my_exeve.h"
#include "my_exe_com_gauche.h"
#include "get_to_path.h"
#include "my_str_in_tab.h"
#include "my_free_tab.h"
#include "aff_key.h"
#include "get_next_line.h"
#include "my_exit.h"
#include "my_strcmp.h"
#include "opt_liste_chaine.h"
#include "my_exeve_gauche.h"
#include "define.h"
#include "extraction_key.h"

int	my_execve2_gauche(char **tab, char **tab2,
			  t_struct *pile, char **my_env_tab)
{
  int	i;

  i = 0;
  pile = pile;
  if (tab2 != NULL)
    {
      while (tab2[i] != 0)
	{
	  if (access(tab2[i], X_OK) == 0)
	    {
	      if (pile->fd == 1)
		{
		  pile->fd = pile->fd_exe;
		  my_xdup2(pile->fd, 1);
		}
	      execve(tab2[i], tab, my_env_tab);
	      return (0);
	    }
	  i++;
	}
    }
  my_putstr(tab[0], 1);
  my_putstr(COM_NOT_FOUND, 1);
  return (0);
}

int	check_com_gauche(char **path, char **tab,
			 t_struct *pile, char **my_env_tab)
{
  int	p[2];
  pid_t	pid;

  if (pipe(p) < 0)
    aff_err("pipe", 0);
  if ((pid = fork()) < 0)
    aff_err("fork", 1);
  if (pid)
    {
      my_xclose(p[0]);
      pile->fd = p[1];
      pile->fd_g = 0;
      my_execve("echo", pile->my_redir_g->data, pile);
      my_xclose(p[1]);
      if (waitpid(pid, 0, 0) == -1)
	return (0);
    }
  else
    {
      my_xclose(p[1]);
      my_xdup2(p[0], 0);
      my_execve2_gauche(tab, path, pile, my_env_tab);
      my_xclose(p[0]);
    }
  return (0);
}

void	my_ex_gauche(t_struct *pile, char *str)
{
  char	**act;
  char	**path;
  char	*tmp;
  char	*opt;
  int	i;
  int	j;
  int	k;

  k = my_list_size(pile->my_env) + 2;
  j = 0;
  i = 0;
  tmp = my_xmalloc(sizeof(*tmp) * (my_strlen(str) + 1));
  opt = my_xmalloc(sizeof(*opt) * (my_strlen(str) + 1));
  pile->my_env_tab = my_xmalloc_v(sizeof(*(pile->my_env_tab)) * k);
  pile->my_env_tab = my_list_in_tab(pile->my_env, pile->my_env_tab);
  my_extrc_gauche(tmp, opt, str);
  path = get_to_path(pile->my_env, tmp);
  act = my_str_in_tab2(opt, tmp);
  check_com_gauche(path, act, pile, pile->my_env_tab);
  my_free_tab(path);
  my_free_tab(act);
  free(act);
  free(path);
  free(opt);
  free(tmp);
}

char	*extraction_keyword(char *str, int i, t_struct *pile)
{
  char	*stop;
  int	n;

  n = 0;
  i = avance(str, 0);
  i += 3;
  stop = NULL;
  if (str[i] != '\0')
    {
      stop = my_xmalloc(sizeof(*stop) * (my_strlen(str) + 1));
      while ((str[i] != '\0') && (str[i + 1] != '>') && str[i + 1] != '<')
	stop[n++] = str[i++];
      stop[n] = '\0';
      aff_key(stop);
      if (str[i] != '\0' && str[i + 1] == '<')
	{
	  free(stop);
	  my_putstr(AMB, 2);
	  return (NULL);
	}
    }
  if (stop == NULL)
    my_putstr(MISSING_NAME, 2);
  extraction_key(str, i, pile);
  return (stop);
}

int	my_exeve_gauche(char *str, t_struct *pile)
{
  char *stop;
  int	i;
  int	j;
  char	*arg;

  j = 0;
  pile->my_redir_g = 0;
  if ((stop = extraction_keyword(str, i, pile)) == NULL)
    return (0);
  while (my_strcmp(arg = get_next_line(0), stop) != 0)
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
  my_exe_gauche(pile, str);
  if (pile->my_redir_g != 0)
    my_free_list(pile->my_redir_g);
  return (0);
}
