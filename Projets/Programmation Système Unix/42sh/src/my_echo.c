/*
** my_echo.c for my_echo in /u/all/algrin_t/cu/rendu/c/minishell2
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Sat Jan 31 12:55:02 2009 thibaut algrin
** Last update Sat Jun 20 12:22:03 2009 remi prsien-
*/

#include "minishell.h"
#include "my_putstr.h"
#include "my_exeve.h"
#include "my_env.h"

int	my_echo(char *opt, t_struct *pile)
{
  int	flag;

  flag = 0;
  gest_pipe(pile);
  redi_opt(pile);
  if ((opt[0] == '-') && (opt[1] == 'n'))
    {
      flag = 1;
      opt = &opt[3];
    }
  my_putstr(opt, pile->fd);
  if (flag == 0)
    my_putchar('\n', pile->fd);
  return (0);
}
