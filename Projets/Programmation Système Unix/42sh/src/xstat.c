/*
** xstat.c for 42sh in /u/epitech_2013/algrin_t/public/42sh
** 
** Made by remi prsien-
** Login   <prsien_r@epitech.net>
** 
** Started on  Fri Jun 19 12:54:22 2009 remi prsien-
** Last update Sat Jun 20 12:20:39 2009 remi prsien-
*/

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int	xstat(char *name, struct stat *sb)
{
  if (stat(name, sb) != 0)
    {
      perror("stat");
      return (EXIT_FAILURE);
    }
  else
    return (EXIT_SUCCESS);
}
