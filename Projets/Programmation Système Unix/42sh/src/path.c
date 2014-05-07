/*
** path.c for path in /u/all/algrin_t/cu/rendu/c/minishell1
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Mon Jan  5 15:57:18 2009 thibaut algrin
** Last update Sun Jun 21 12:37:28 2009 thibaut algrin
*/

#include "minishell.h"
#include "my_xmalloc.h"
#include "my_strcpy.h"
#include "my_putstr.h"

void	new_elem(char *arg, t_list **my_env)
{
  t_list	*new;

  new = my_xmalloc_v(sizeof(*new));
  if (arg != NULL)
    {
      new->data = my_xmalloc(sizeof(*new->data) * (my_strlen(arg) + 1));
      new->data = my_strcpy(new->data, arg);
    }
  new->next = *my_env;
  new->prev = 0;
  if (*my_env)
    (*my_env)->prev = new;
  *my_env = new;
}
