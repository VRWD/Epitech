/*
** my_cd.c for 42sh in /u/all/algrin_t/cu/rendu/c/42sh
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Mon Jun  1 09:59:18 2009 thibaut algrin
** Last update Sun Jun 21 20:34:46 2009 thibaut algrin
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include "minishell.h"
#include "define.h"
#include "my_putstr.h"
#include "my_strcat.h"
#include "path.h"
#include "my_setenv.h"
#include "opt_liste_chaine.h"
#include "my_strcpy.h"
#include "my_xmalloc.h"
#include "my_free_tab.h"
#include "my_strcmp.h"
#include "my_cd_opt.h"
#include "cd_check.h"

char	**my_str_towordtab_cd(char *buffer, char c)
{
  int	i;
  int	n;
  int	k;
  char	**tab;

  n = 0;
  k = 0;
  i = 0;
  tab = my_xmalloc_v(sizeof(*tab) * (my_strlen(buffer) + 2));
  tab[0] = my_xmalloc(sizeof(*tab[0]) * (my_strlen(buffer) + 1));
  while (buffer[i] != '\0')
    {
      if ((buffer[i] == c && buffer[i + 1] != c)
	  && (i >= 2) && (buffer[i + 1] != '\0'))
	{
	  i++;
	  tab[n][k] = '\0';
	  tab[++n] = my_xmalloc(sizeof(*tab[0]) * (my_strlen(buffer) + 1));
	  k = 0;
	}
      tab[n][k++] = buffer[i++];
    }
  tab[n][k] = '\0';
  tab[n + 1] = 0;
  return (tab);
}

void	find_cd(char *str, t_struct *pile)
{
  int	n;
  int	flag;
  char	*tmp;
  char	**path;

  n = 0;
  flag = 0;
  tmp = my_strdup(str);
  path = my_str_towordtab_cd(tmp, '/');
  while (path[n] != 0)
    {
      if (path[n + 1] == 0)
	flag = 1;
      if (my_strncmp(path[n], "..", 2) == 0)
	my_cd_back(pile, flag);
      else if ((n == 0) && (path[n][0] == '-'))
	my_cd_minus(path[n], pile);
      else
	my_cd_opendir(path[n], pile, flag);
      n++;
    }
  my_free_tab(path);
  free(path);
  free(tmp);
}

void	msg_error(char *str, char *msg, t_struct *pile)
{
  my_putstr(str, 2);
  my_putstr(msg, 2);
  (pile->seg[0] == OK) ? pile->e = NOT_OK : 0;
  (pile->seg[1] == OK) ? pile->e = OK : 0;
}

int	check_perm(struct stat s, char *tmp)
{
  DIR	*dir;

  if ((tmp != NULL) && ((tmp[0] == '-') || ((dir = opendir(tmp)) != NULL)))
    {
      if ((s.st_mode & S_IRUSR) &&
	  (s.st_mode & S_IRGRP) && (s.st_mode & S_IROTH))
	return (0);
    }
  return (1);
}

int		my_cd(char *str, t_struct *pile)
{
  struct stat	s;
  int		n;
  char		*tmp;

  n = 0;
  tmp = NULL;
  if ((str != NULL) && (*str == 0))
    str = my_aff_param_list(pile->my_env, HOME);
  if (str == NULL)
    str = my_strdup(pile->home);
  if ((str != NULL) && (str[0] != '/') && (str[0] != '-') && str[0] != '.')
    tmp = my_strcat("./", str);
  else if (str != NULL)
    tmp = my_strdup(str);
  if ((str != NULL) && (str[0] != '-') && (stat(tmp, &s) < 0))
    {
      msg_error(str, NO_FILE_DIR, pile);
      return (0);
    }
  if ((str != NULL) && ((str[0] == '-') || (check_perm(s, tmp) == 0)))
    find_cd(tmp, pile);
  else
    msg_error(str, ": Permission denied\n", pile);
  cd_check(tmp);
  return (0);
}
