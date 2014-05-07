/*
** my_putstr.c for my_putstr in /u/all/algrin_t/cu/rendu/c/minishell1
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Tue Dec 30 17:01:00 2008 thibaut algrin
** Last update Fri Jun 19 17:39:25 2009 thibaut algrin
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "minishell.h"
#include "my_putstr.h"

void	my_putchar(char c, int fd)
{
  if (write(fd, &c, 1) == -1)
    {
      my_putstr("Can not write here\n", 1);
      exit(EXIT_FAILURE);
    }
}

int	my_putstr(char *str, int fd)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    {
      my_putchar(str[i], fd);
      i++;
    }
  return (0);
}

int	my_putstr2(char *str, int i, int fd)
{
  if (i >= my_strlen(str))
    return (0);
  while (str[i] != '\0')
    {
      my_putchar(str[i], fd);
      i++;
    }
  return (0);
}

int	my_putstr_to_c(char *str, char c, int fd)
{
  int	i;

  i = 0;
  while ((str[i] != '\0') && (str[i] != c))
    {
      my_putchar(str[i], fd);
      i++;
    }
  return (0);
}

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
