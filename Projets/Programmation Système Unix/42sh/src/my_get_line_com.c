/*
** my_get_line_com.c for 42sh in /u/epitech_2013/prsien_r/public/42/42FINAL
** 
** Made by thomas stelletta
** Login   <stelle_t@epitech.net>
** 
** Started on  Mon May 25 18:14:58 2009 thomas stelletta
** Last update Sun Jun 21 18:51:01 2009 remi prsien-
*/

#include <stdlib.h>
#include "my_xmalloc.h"
#include "minishell.h"
#include "put_argv_in_tab.h"
#include "mysh.h"
#include "put_argv_in_tab.h"
#include "my_get_line_com.h"

char		**my_get_line_com(char *tmp)
{
  t_structs	*str_tab;
  char		*space;
  char		**tab;

  str_tab = my_xmalloc_v(sizeof(*str_tab));
  space = put_space_in_str(tmp);
  tab = put_argv_in_tab(space, str_tab);
  free(str_tab);
  free(space);
  return (tab);
}
