/*
** go_init.c for 42sh in /u/epitech_2013/algrin_t/public/42sh
** 
** Made by remi prsien-
** Login   <prsien_r@epitech.net>
** 
** Started on  Sun Jun 21 20:13:46 2009 remi prsien-
** Last update Sun Jun 21 20:18:49 2009 remi prsien-
*/

#include "minishell.h"
#include "go_init.h"
#include "mysh.h"

void	go_init(char **tab, int n, t_struct *pile)
{
  initialisation(tab[n], pile);
  if (pile->tmp != NULL)
    free(pile->tmp);
}
