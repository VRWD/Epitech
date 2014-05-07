/*
** my_cd_opdir.c for 42sh in /u/epitech_2013/algrin_t/public/42sh
** 
** Made by remi prsien-
** Login   <prsien_r@epitech.net>
** 
** Started on  Sun Jun 21 19:32:58 2009 remi prsien-
** Last update Sun Jun 21 19:53:42 2009 remi prsien-
*/

#include "minishell.h"
#include "path.h"
#include "my_setenv.h"
#include "my_strcat.h"
#include "my_putstr.h"
#include "define.h"
#include "my_cd_opdir.h"

int	my_cd_opdir(a_list *ab, char *str, int flag, t_struct *pile)
{
  ab->path = my_strcat2(ab->pwd, str, '/');
  ab->n = my_strlen(ab->path);
  if (ab->path[my_strlen(ab->path) - 1] == '/')
    while (ab->path[ab->n - 1] == '/')
      ab->n--;
  ab->path[ab->n] = '\0';
  free(ab->pwd);
  if (chdir(ab->path) == -1)
    {
      (pile->seg[0] == OK) ? pile->e = NOT_OK : 0;
      (pile->seg[1] == OK) ? pile->e = OK : 0;
      my_putstr(ab->path, 2);
      free(ab->path);
      my_putstr(NO_FILE_DIR, 2);
      return (0);
    }
  if (flag == 1)
    new_elem(ab->path, &pile->save_cd);
  ab->pwd = my_strcat("PWD ", ab->path);
  my_setenv(ab->pwd, pile);
  free(ab->pwd);
  free(ab->path);
  return (0);
}
