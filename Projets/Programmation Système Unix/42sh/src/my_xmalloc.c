/*
** my_xmalloc.c for 42sh in /u/epitech_2013/algrin_t/public/42sh
** 
** Made by remi prsien-
** Login   <prsien_r@epitech.net>
** 
** Started on  Sat Jun 20 13:14:27 2009 remi prsien-
** Last update Sat Jun 20 13:14:28 2009 remi prsien-
*/

#include <stdlib.h>
#include "minishell.h"
#include "define.h"
#include "my_putstr.h"
#include "my_xmalloc.h"

char	*reset(char *str, int nb)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (NULL);
  while (i < nb)
    {
      str[i] = '\0';
      i++;
   }
  return (str);
}

char		*my_xmalloc(int nb)
{
  char		*mal;

  mal = malloc(nb);
  if (mal == 0)
    {
      my_putstr(MALLOC_FAILED, 2);
      exit(EXIT_FAILURE);
    }
  mal = reset(mal, nb);
  return (mal);
}

void		*my_xmalloc_v(int nb)
{
  void		*mal;

  mal = malloc(nb);
  if (mal == 0)
    {
      my_putstr(MALLOC_FAILED, 2);
      exit(EXIT_FAILURE);
    }
  return (mal);
}
