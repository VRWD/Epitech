/*
** redirection.c for redirection in /u/all/algrin_t/cu/rendu/c/minishell2
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Sun Feb 22 19:02:18 2009 thibaut algrin
** Last update Sun Jun 21 22:39:26 2009 thibaut algrin
*/

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "minishell.h"
#include "define.h"
#include "my_xmalloc.h"
#include "my_putstr.h"
#include "redirection.h"
#include "extraction_com_opt.h"
#include "xfonction.h"
#include "my_exeve_gauche.h"
#include "my_redir_optsec.h"

int	xstat(char *name, struct stat *sb);

int	can_access(char *str, int i, int j)
{
  struct stat	sb;

  if (j == 1)
    if (access(str, F_OK) == -1)
      i = 3;
  if (i == 0)
    if (access(str, F_OK) == -1)
      {
	my_putstr(str, 2);
	my_putstr(NO_FILE_DIR, 2);
	return (1);
      }
  if (i == 1)
    {
      xstat(str, &sb);
      if ((sb.st_mode & S_IFMT) == S_IFDIR)
	{
	  my_putstr(str, 2);
	  my_putstr(" : Is a directory.\n", 2);
	  return (1);
	}
    }
  return (0);
}

int	redirection_droite(t_struct *pile, char *str, int i)
{
  char	*tmp;
  int	k;

  i++;
  tmp = extraction_file(str, i, tmp, pile);
  if (tmp != NULL)
    {
      if (can_access(tmp, 1, 1) == 1)
	return (NOT_OK);
      k = open(tmp, O_CREAT | O_RDWR | O_TRUNC, 0777);
      if (k == -1)
	aff_err("open", 1);
      free(tmp);
      pile->red_d = 0;
      if (k != -1)
	pile->fd = k;
    }
  else
    {
      my_putstr(INV_COM, 2);
      return (NOT_OK);
    }
  return (OK);
}

int	redirection_gauche(t_struct *pile, char *str, int i)
{
  int	flag;
  char	*tmp;

  i++;
  flag = 0;
  tmp = extraction_file(str, i, tmp, pile);
  if (tmp != NULL)
    {
      if (can_access(tmp, 0, 0) == 1)
	return (NOT_OK);
      if (redir_leftsec(tmp, flag, pile) == NOT_OK)
	return (NOT_OK);
    }
  else
    {
      my_putstr(INV_COM, 2);
      return (NOT_OK);
    }
  return (OK);
}

int	redirection_double_droite(t_struct *pile, char *str, int i)
{
  char	*tmp;
  int	k;

  i += 2;
  tmp = extraction_file_double(str, i, tmp);
  if (tmp != NULL)
    {
      k = open(tmp, O_APPEND | O_RDWR | O_CREAT, 0777);
      if (k == -1)
	aff_err("open", 1);
      if (k != -1)
	pile->fd = k;
      free(tmp);
      pile->red_dd = 0;
    }
  else
    {
      my_putstr(INV_COM, 2);
      return (NOT_OK);
    }
  return (OK);
}

void	my_redir_opt(char *str, int i, t_struct *pile)
{
  if (str[i - 1] != '\0' && str[i] != '\0')
    {
      if ((str[i] == '>') && (str[i + 1] != '>') && (str[i] != '\0'))
	pile->red_d = 1;
      else if ((str[i] == '>') && (str[i + 1] == '>'))
	pile->red_dd = 1;
      else if ((str[i] == '<') && (str[i + 1] != '<'))
	pile->red_g = 1;
      else if ((str[i] == '|') && (str[i + 1] != '|'))
	pile->flag_pipe = 1;
      else if ((str[i] == '<') && (str[i + 1] == '<'))
	my_redir_optsec(str, pile, 0);
      else if ((str[i] == '|') && (str[i + 1] == '|'))
	my_redir_optsec(str, pile, 1);
      else if ((str[i] == '&') && (str[i + 1] == '&'))
	my_redir_optsec(str, pile, 2);
      else if (str[i] == ';')
	my_redir_optsec(str, pile, 3);
    }
  if (pile->red_d == 1 && pile->tmp[1] == '<')
    {
      my_putstr(AMB, 2);
      return ;
    }
}
