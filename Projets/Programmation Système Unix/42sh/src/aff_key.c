/*
** aff_key.c for 42sh in /u/all/algrin_t/cu/rendu/c/42sh
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Tue May 12 14:54:14 2009 thibaut algrin
** Last update Tue May 19 16:03:57 2009 thibaut algrin
*/

#include "minishell.h"
#include "my_putstr.h"
#include "aff_key.h"
#include "define.h"

void	aff_key(char *stop)
{
  my_putstr(KEY_CODE, 1);
  my_putstr(stop, 1);
  my_putstr("\n", 1);
  my_putstr(SYM_RED_G, 1);
}
