/*
** my_strcpy.c for my strcpy in /u/all/algrin_t/cu/rendu/piscine/Jour_06
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Mon Oct 13 10:26:51 2008 thibaut algrin
** Last update Fri Jun 19 18:09:06 2009 thibaut algrin
*/

#include "minishell.h"
#include "my_xmalloc.h"
#include "my_putstr.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strdup(char *src)
{
  int	i;
  char	*dest;

  i = 0;
  if (src == NULL)
    return (NULL);
  dest = my_xmalloc(sizeof(*dest) * (my_strlen(src) + 1));
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
