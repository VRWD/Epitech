/*
** my_redir_optsec.c for 42sh in /u/epitech_2013/algrin_t/public/42sh
** 
** Made by remi prsien-
** Login   <prsien_r@epitech.net>
** 
** Started on  Sun Jun 21 15:27:22 2009 remi prsien-
** Last update Sun Jun 21 18:05:01 2009 remi prsien-
*/

#include <fcntl.h>
#include "minishell.h"
#include "define.h"
#include "my_exeve_gauche.h"
#include "my_putstr.h"
#include "redirection.h"

int	redir_leftsec(char *tmp, int flag, t_struct *pile)
{
  int	k;

  k = open(tmp, O_RDONLY);
  if (can_access(tmp, 1, 0) == 1)
    return (NOT_OK);
  if (k == -1)
    {
      my_putstr("Access Denied", 2);
      flag = 1;
    }
  free(tmp);
  pile->red_g = 0;
  pile->fd_g = k;
  if (flag == 1)
    return (NOT_OK);
  return (OK);
}

void	my_redir_optsec(char *str, t_struct *pile, int flag)
{
  if (flag == 0)
    {
      my_exeve_gauche(str, pile);
      pile->flag_ddg = 1;
    }
  else if (flag == 1)
    {
      pile->e = NOT_OK;
      pile->seg[1] = OK;
    }
  else if (flag == 2)
    {
      pile->e = OK;
      pile->seg[0] = OK;
    }
  else if (flag == 3)
    {
      pile->seg[2] = OK;
      pile->seg[0] = NOT_OK;
      pile->seg[1] = NOT_OK;
      pile->e = OK;
    }
}
