/*
** help_prompt.c for 42sh in /u/all/algrin_t/cu/rendu/c/42sh
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Mon Apr 13 13:49:55 2009 thibaut algrin
** Last update Mon Apr 20 14:52:25 2009 thibaut algrin
*/

#include "minishell.h"

int	help_prompt(char *opt, t_struct *pile)
{
  opt = opt;
  pile = pile;
  my_putstr("%h:\tpermet d'afficher la machine ou vous vous trouvez\n", 1);
  my_putstr("%p:\tpermet d'afficher le dossier ou vous etes\n", 1);
  my_putstr("%n:\tpermet d'afficher l'utilisateur\n", 1);
  return (0);
}
