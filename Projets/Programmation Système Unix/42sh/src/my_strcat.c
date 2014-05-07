/*
** my_strcat.c for my strcat in /u/epitech_2013/algrin_t/cu/rendu/piscine/Jour_07
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Wed Oct 15 18:28:40 2008 thibaut algrin
** Last update Mon May 25 17:43:15 2009 thibaut algrin
*/

#include "minishell.h"
#include "my_putstr.h"
#include "my_xmalloc.h"

char	*my_strcat(char *str1, char *str2)
{
  int	i;
  int	j;
  char	*str3;

  j = 0;
  i = 0;
  str3 = my_xmalloc(sizeof(str3) * (my_strlen(str1) + my_strlen(str2) + 5));
  while (str1[i] != '\0')
    {
      str3[i] = str1[i];
      i++;
    }
  if (str2 != NULL)
    while (str2[j] != '\0')
      str3[i++] = str2[j++];
  str3[i] = '\0';
  return (str3);
}

char    *my_strcat2(char *str1, char *str2, char c)
{
  int   i;
  int   j;
  char  *str3;

  i = 0;
  j = 0;
  str3 = my_xmalloc(sizeof(str3) * (my_strlen(str1) + my_strlen(str2) + 1));
  while (str1[i] != '\0')
    {
      str3[i] = str1[i];
      i++;
    }
  str3[i++] = c;
  while (str2[j] != '\0')
      str3[i++] = str2[j++];
  str3[i] = '\0';
  return (str3);
}

char	*my_strcat3(char *str1, char *str2)
{
  int	i;
  int	j;
  char	*str3;

  j = 0;
  i = 0;
  str3 = my_xmalloc(sizeof(str3) * (my_strlen(str1) + my_strlen(str2) + 1));
  while (str1[i] != '\0')
    {
      str3[i] = str1[i];
      i++;
    }
  if (str2 != NULL)
    while (str2[j] != '\0')
      str3[i++] = str2[j++];
  str3[i] = '\0';
  free(str1);
  return (str3);
}
