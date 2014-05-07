/*
** aff_err.c for 42sh in /u/all/algrin_t/cu/rendu/c/42sh
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Wed Apr 29 12:20:55 2009 thibaut algrin
** Last update Tue May 26 15:50:28 2009 remi prsien-
*/

#include "minishell.h"
#include "define.h"
#include "my_putstr.h"
#include "aff_err.h"

void	aff_inval_null(char *str)
{
  if (str[0] == '|')
    my_putstr(INV_COM, 2);
}
