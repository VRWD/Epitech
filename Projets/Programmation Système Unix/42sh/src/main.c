/*
** main.c for main in /u/all/algrin_t/cu/rendu/c/minishell2bis
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Thu Feb  5 08:47:32 2009 thibaut algrin
** Last update Sun Jun 21 20:52:39 2009 thibaut algrin
*/

#include <fcntl.h>
#include "minishell.h"
#include "go_init.h"
#include "my_xmalloc.h"
#include "my_putstr.h"
#include "mysh.h"
#include "my_strcmp.h"
#include "my_strcpy.h"
#include "my_check_alias.h"
#include "my_free_tab.h"
#include "opt_liste_chaine.h"
#include "conf.h"
#include "path.h"
#include "aff_prompt.h"
#include "define.h"
#include "put_argv_in_tab.h"
#include "my_get_line_com.h"

int		operation(char *tmp, t_struct *pile)
{
  int		n;
  char		**tab;

  n = 0;
  tab = my_get_line_com(tmp);
  while (tab[n] != 0)
    {
      pile->fd = 1;
      pile->fd_g = 0;
      tab[n] = my_check_alias(tab[n], pile);
      if (my_strcmp(tab[n], EXIT) == 0)
	{
	  pile->flag_exit = OK;
	  break;
	}
      if ((tab[n] != 0) && (pile->e == OK) && (my_strcmp(tab[n], EXIT) != 0))
	go_init(tab, n, pile);
      else if (pile->e == NOT_OK)
	pile->e = OK;
      n++;
    }
  my_free_tab(tab);
  free(tab);
  return (0);
}

char	*catch_pwd(char	*env, t_struct *pile)
{
  int	i;
  int	k;
  char	*str;

  i = 0;
  k = 0;
  str = my_xmalloc(sizeof(*str) * (my_strlen(env) + 1));
  while (env[i] != '=' && env[i] != '\0')
    i++;
  i++;
  while (env[i] != '\0')
    str[k++] = env[i++];
  pile->pwd = my_strdup(str);
  new_elem(str, &pile->save_cd);
  free(str);
  return (str);
}

void	mysh_param(char **env, t_struct *pile)
{
  int		flag;
  int		n;

  n = 0;
  flag = 0;
  pile->my_env = 0;
  pile->hist = 0;
  pile->save_cd = 0;
  while (env[n] != 0)
    {
      if (env[n] != 0 && my_strncmp(PWD, env[n], 3) == 0)
	catch_pwd(env[n], pile);
      add_elem_to_liste(env[n], &pile->my_env);
      n++;
      if (env[n] != 0)
	flag = 1;
    }
  if (flag == 1)
    while (pile->my_env->prev)
      pile->my_env = pile->my_env->prev;
  pile->home = my_aff_param_list(pile->my_env, HOME);
  init_variable(pile);
  fichier_conf(pile);
  aff_prompt(pile);
}

int	version(int argc, char **argv)
{
  if (argc == 2)
    {
      if (my_strcmp(argv[1], "--v") == 0)
	{
	  my_putstr(SUJET, 1);
	  my_putstr(VERSION, 1);
	  my_putstr(DATE, 1);
	  my_putstr(AUTEURS, 1);
	  return (1);
	}
    }
  return (0);
}

int		main(int argc, char **argv, char **env)
{
  t_struct	pile;

  pile.i = 0;
  pile.conf = NULL;
  pile.pwd = NULL;
  pile.my_alias = 0;
  if (pile.my_alias != 0)
    while (pile.my_alias->prev != 0)
      pile.my_alias = pile.my_alias->prev;
  if (version(argc, argv) == 1)
    return (0);
  my_putstr("42SH:\n", 1);
  mysh_param(env, &pile);
  return (0);
}
