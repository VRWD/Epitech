/*
** command_not_found.c for 42sh in /u/all/prsien_r/cu/public/42/42FINAL
** 
** Made by remi prsien-
** Login   <prsien_r@epitech.net>
** 
** Started on  Tue May 26 15:35:30 2009 remi prsien-
** Last update Fri Jun 19 17:28:45 2009 thibaut algrin
*/

#include "minishell.h"
#include "command_not_found.h"
#include "my_putstr.h"
#include "define.h"

void	command_not_found(t_struct *pile, char **tab)
{
  pile->red_d = 0;
  pile->red_g = 0;
  pile->red_dd = 0;
  my_putstr(tab[0], 1);
  (pile->seg[0] == OK) ? pile->e = NOT_OK : 0;
  (pile->seg[1] == OK) ? pile->e = OK : 0;
  my_putstr(COM_NOT_FOUND, 1);
}
