/*
** xfunc.c for 42sh in /u/all/algrin_t/cu/public/42sh
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Sun Jun 21 20:01:55 2009 thibaut algrin
** Last update Sun Jun 21 20:05:06 2009 thibaut algrin
*/

#include <unistd.h>
#include "my_putstr.h"
#include "define.h"

int	xchdir(char *str)
{
  if (chdir(str) == -1)
    {
      my_putstr(str, 2);
      my_putstr(NO_FILE_DIR, 2);
      return (-1);
    }
  return (0);
}
