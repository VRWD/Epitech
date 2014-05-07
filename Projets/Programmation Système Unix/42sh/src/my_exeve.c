/*
** my_exeve.c for my_exeve in /u/all/algrin_t/cu/rendu/c/minishell1
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Tue Jan 27 14:31:10 2009 thibaut algrin
** Last update Sun Jun 21 21:29:41 2009 thibaut algrin
*/

#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "minishell.h"
#include "command_not_found.h"
#include "xfonction.h"
#include "my_putstr.h"
#include "my_xmalloc.h"
#include "my_list_size.h"
#include "my_strcpy.h"
#include "get_to_path.h"
#include "my_str_in_tab.h"
#include "my_free_tab.h"
#include "my_env.h"
#include "gest_err.h"
#include "my_exeve.h"
#include "define.h"

int	gest_pipe(t_struct *pile)
{
  if (pile->flag_pipe == 1)
    {
      my_xpipe(pile->p);
      pile->fd = pile->p[0];
      pile->flag_pipe = 0;
    }
  return (0);
}

int	check_com(char *path, char **com, t_struct *pile, char **my_env_tab)
{
  pid_t	pid;
  int	status;

  status = 0;
  if (redi_opt(pile) == NOT_OK)
    return (0);
  gest_pipe(pile);
  if ((pid = fork()) < 0)
    aff_err("fork", 0);
  if (pid > 0)
    {
      if ((my_strcmp(MAYA, pile->host) != 0) &&
	  (pile->fd == 1) && (pile->ex_red != 1))
	{
	  if (waitpid(pid, &status, 0) == -1)
	    return (0);
	}
      else if (pile->ex_red == 1)
	if (waitpid(pid, &status, 0) == -1)
	  return (0);
      gest_err(status, pile);
    }
  else
    {
      my_xdup2(pile->fd, 1);
      my_xdup2(pile->fd_g, 0);
      execve(path, com, my_env_tab);
      exit(0);
    }
  return (0);
}

int	my_execve2(char **tab, char **tab2, t_struct *pile, char **my_env_tab)
{
  int	i;

  i = 0;
  if (tab2 != NULL)
    {
      while (tab2[i] != 0)
	{
	  if (access(tab2[i], X_OK) == 0)
	    {
	      check_com(tab2[i], tab, pile, my_env_tab);
	      pile->fd = 1;
	      if ((pile->flag_pipe == 1))
		my_xclose(pile->p[1]);
	      return (0);
	    }
	  i++;
	}
    }
  command_not_found(pile, tab);
  return (0);
}

char		**my_list_in_tab(t_list *begin, char **my_env)
{
  int		n;
  t_list	*save;

  n = 0;
  save = begin;
  while (save != 0)
    {
      my_env[n] = my_xmalloc(sizeof(*my_env[n]) * (my_strlen(save->data) + 1));
      my_env[n] = my_strcpy(my_env[n], save->data);
      n++;
      save = save->next;
    }
  my_env[n] = 0;
  return (my_env);
}

int	my_execve(char *tmp, char *opt, t_struct *pile)
{
  char	**act;
  char	**path;
  char	**my_env_tab;
  int	k;

  k = my_list_size(pile->my_env) + 2;
  path = get_to_path(pile->my_env, tmp);
  my_env_tab = my_xmalloc_v(sizeof(*my_env_tab) * k);
  my_env_tab = my_list_in_tab(pile->my_env, my_env_tab);
  act = my_str_in_tab2(opt, tmp);
  my_execve2(act, path, pile, my_env_tab);
  if (act != 0)
    my_free_tab(act);
  if (path != 0)
    my_free_tab(path);
  if (my_env_tab != 0)
    my_free_tab(my_env_tab);
  free(my_env_tab);
  free(act);
  free(path);
  if ((pile->fd != 0) && (pile->fd != 1) && (pile->fd != 2))
    my_xclose(pile->fd);
  if ((pile->fd_g != 0) && (pile->fd_g != 1) && (pile->fd_g != 2))
    my_xclose(pile->fd_g);
  return (0);
}
