/*
** my_exe_com_gauche.c for my_exe_com_gauche in /u/all/algrin_t/cu/rendu/c/minishell2
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Thu Feb 26 14:30:27 2009 thibaut algrin
** Last update Sun Jun 21 21:24:15 2009 thibaut algrin
*/

#include "minishell.h"
#include "my_exeve_gauche.h"

int	avance(char *str, int i)
{
  while ((str[i] != '<') && (str[i] != '\0'))
    i++;
  return (i);
}

void	my_extrc_gauche(char *tmp, char *opt, char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while ((str[i] != ' ') && (str[i] != '\0'))
    {
      tmp[i] = str[i];
      i++;
    }
  tmp[i] = '\0';
  i++;
  while (str[i] != '<' && str[i] != '\0')
    opt[j++] = str[i++];
  opt[j] = '\0';
}

void	my_exe_gauche(t_struct *pile, char *str)
{
  if (pile->my_redir_g != 0)
    {
      while (pile->my_redir_g->next != 0)
	{
	  my_ex_gauche(pile, str);
	  pile->my_redir_g = pile->my_redir_g->next;
	}
      my_ex_gauche(pile, str);
    }
}
