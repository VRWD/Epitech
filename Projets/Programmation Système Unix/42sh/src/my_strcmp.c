/*
** my_strcmp.c for my strcmp in /u/epitech_2013/algrin_t/cu/rendu/piscine/Jour_06
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Tue Oct 14 14:25:28 2008 thibaut algrin
** Last update Fri May 22 15:43:34 2009 thibaut algrin
*/

#include <stdlib.h>
#include "minishell.h"
#include "my_putstr.h"

int     my_strcmp(char *s1, char *s2)
{
  int   i;

  i = 0;
  if (s1 == NULL)
    return (0);
  if (my_strlen(s1) != my_strlen(s2))
    return (1);
  while (s1[i] != '\0')
    {
      if ((s1[i] != s2[i]) || s1 == '\0' || s2 == '\0')
	return (1);
       i = i + 1;
    }
  return (0);
}

int     my_strncmp(char *s1, char *s2, int n)
{
  int   i;
  int	j;

  j = 0;
  i = 0;
  while ((s2[i] != '\0') && (i < n))
    {
      if (s1[i] != s2[i])
        return (1);
      i = i + 1;
    }
  return (0);
}

int     my_strcmp2(char *s1, char *s2)
{
  int	n;
  int   i;
  int	j;

  j = 0;
  i = 0;
  n = 0;
  while ((s2[n] != '=') && (s2[n] != '\0'))
    n++;
  if (my_strlen(s1) < n)
    return (1);
  while ((s1[i] != '\0') && (i < n))
    {
      if (s1[i] != s2[i])
        return (1);
      i = i + 1;
    }
  return (0);
}

int     my_strcmp3(char *s1, char *s2)
{
  int	n;
  int   i;
  int	j;

  j = 0;
  i = 0;
  n = 0;
  while ((s2[n] != ' ') && (s2[n] != '\0'))
    n++;
  if (my_strlen(s1) < n)
    return (1);
  while ((s1[i] != '\0') && (i < n))
    {
      if (s1[i] != s2[i])
        return (1);
      i = i + 1;
    }
  return (0);
}
