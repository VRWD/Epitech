/*
** my_getpwd.c for 42sh in /u/epitech_2013/algrin_t/public/42sh
** 
** Made by remi prsien-
** Login   <prsien_r@epitech.net>
** 
** Started on  Sun Jun 21 19:19:15 2009 remi prsien-
** Last update Sun Jun 21 19:26:31 2009 remi prsien-
*/

#include "minishell.h"
#include "my_xmalloc.h"

char	*my_getpwd(char *pwd)
{
  pwd = my_xmalloc((4096) * sizeof(*pwd));
  getcwd(pwd, 4096);
  return (pwd);
}
