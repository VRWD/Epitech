/*
** minishell.h for minishell.h in /u/all/algrin_t/cu/rendu/c/minishell1bis
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Mon Jan 19 11:58:24 2009 thibaut algrin
** Last update Sun Jun 21 17:15:58 2009 remi prsien-
*/

#ifndef MINISHELL_H_
# define MINISHELL_H_

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

# define	OK		0
# define	NOT_OK		1

typedef struct	s_list
{
  char		*data;
  char		*data2;
  struct s_list	*next;
  struct s_list	*prev;
}		t_list;

typedef	struct	s_struct
{
  int		fd;
  char		*home;
  char		*conf;
  char		*tmp;
  char		*user;
  char		*pwd;
  char		*host;
  int		ex_red;
  int		fd_exe;
  int		flag_exit;
  int		alias_i;
  int		seg[3];
  int		e;
  int		in;
  int		flag_init;
  int		init;
  int		red_d;
  int		red_g;
  int		red_dd;
  int		pos;
  int		flag_ddg;
  int		fd_g;
  int		flag_pipe;
  int		p[2];
  int		i;
  char		**my_env_tab;
  t_list	*my_env;
  t_list	*my_redir_g;
  t_list	*my_alias;
  t_list	*save_cd;
  t_list	*hist;
}		t_struct;

#endif /* !MINISHELL_H_ */
