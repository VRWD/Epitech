/*
** my_cd_opt.c for 42sh in /u/all/algrin_t/cu/rendu/c/42sh
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Thu Jun  4 11:45:33 2009 thibaut algrin
** Last update Sun Jun 21 20:48:54 2009 remi prsien-
*/

#include "minishell.h"
#include "define.h"
#include "opt_liste_chaine.h"
#include "my_putstr.h"
#include "my_strcat.h"
#include "my_strcpy.h"
#include "my_setenv.h"
#include "path.h"
#include "my_xmalloc.h"
#include "my_getpwd.h"
#include "xfunc.h"
#include "my_cd_opdir.h"

int	my_cd_back(t_struct *pile, int flag)
{
  int	i;
  char	*pwd;

  pwd = my_aff_param_list(pile->my_env, PWD);
  if (pwd == NULL)
    pwd = my_getpwd(pwd);
  if (pwd != NULL)
    {
      i = my_strlen(pwd) - 1;
      if (pwd[i] == '/')
	i--;
      while ((i > 0) && (pwd[i] != '/'))
	i--;
      if (i >= 0)
	pwd[i] = '\0';
      if (flag == 1)
	new_elem(pwd, &pile->save_cd);
      chdir(pwd);
      pwd = my_strcat("PWD ", pwd);
      my_setenv(pwd, pile);
    }
  else
    my_putstr("You can't go to this directory\n", 2);
  return (0);
}

int	my_cd_null(t_struct *pile, int flag)
{
  char	*path;
  char	*home;

  home = my_aff_param_list(pile->my_env, HOME);
  if (home == NULL)
    home = pile->home;
  if (home != NULL)
    {
      if (chdir(home) == -1)
	{
	  (pile->seg[0] == OK) ? pile->e = NOT_OK : 0;
	  (pile->seg[1] == OK) ? pile->e = OK : 0;
	  free(home);
	  my_putstr(NO_FILE_DIR, 2);
	  return (0);
	}
      if (flag == 1)
	new_elem(home, &pile->save_cd);
      path = my_strcat("PWD ", home);
      free(home);
      my_setenv(path, pile);
      free(path);
    }
  else
    my_putstr("You can't go to this directory\n", 2);
  return (0);
}

int	my_cd_opendir(char *str, t_struct *pile, int flag)
{
  a_list ab;

  ab.path = NULL;
  if (str[0] != '/')
    {
      if (str[0] == '.' && str[1] == '/')
	str = &str[2];
      ab.pwd = my_aff_param_list(pile->my_env, PWD);
      if (ab.pwd == NULL)
	ab.pwd = pile->pwd;
      if (ab.pwd != NULL)
	my_cd_opdir(&ab, str, flag, pile);
    }
  else
    {
      if (xchdir(str) == -1)
	return (0);
      if (flag == 1)
	new_elem(str, &pile->save_cd);
      str = my_strcat("PWD ", str);
      my_setenv(str, pile);
    }
  return (0);
}

int	my_cd_minus(__attribute__((unused))char *str, t_struct *pile)
{
  char	*here;
  char	*tmp;
  t_list *new;

  if ((pile->save_cd != 0) && (pile->save_cd->next != 0))
    {
      while (pile->save_cd->prev != 0)
	pile->save_cd = pile->save_cd->prev;
      new = pile->save_cd->next;
      new->prev = 0;
      pile->save_cd = new;
      here = my_strdup(pile->save_cd->data);
      chdir(here);
      tmp = my_strcat("PWD ", pile->save_cd->data);
      my_setenv(tmp, pile);
    }
  return (0);
}
