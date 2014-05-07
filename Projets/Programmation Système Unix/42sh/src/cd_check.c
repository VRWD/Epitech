/*
** cd_check.c for 42sh in /u/epitech_2013/algrin_t/public/42sh
** 
** Made by remi prsien-
** Login   <prsien_r@epitech.net>
** 
** Started on  Sun Jun 21 20:24:06 2009 remi prsien-
** Last update Sun Jun 21 20:31:14 2009 remi prsien-
*/

#include <stdlib.h>
#include "cd_check.h"

void	cd_check(char *tmp)
{
  if (tmp != NULL)
    free(tmp);
}
