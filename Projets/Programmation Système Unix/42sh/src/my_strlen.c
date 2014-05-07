/*
** my_strlen.c for my_strlen in /u/all/algrin_t/cu/rendu/c/minishell1
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Mon Dec 22 13:56:12 2008 thibaut algrin
** Last update Mon Feb 23 18:31:19 2009 thibaut algrin
*/

#include "minishell.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (1);
  while (str[i] != '\0')
    i++;
  return (i);
}
