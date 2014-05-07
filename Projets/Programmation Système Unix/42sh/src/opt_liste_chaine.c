/*
** opt_liste_chaine.c for opt_list_chaine in /u/all/algrin_t/cu/rendu/c/minishell2
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Mon Feb 23 12:32:24 2009 thibaut algrin
** Last update Sat Jun 20 13:10:59 2009 thibaut algrin
*/

#include "minishell.h"
#include "my_putstr.h"
#include "my_xmalloc.h"
#include "my_strcmp.h"
#include "my_strcpy.h"

char	*remplacement(char *opt)
{
  int	i;
  char	*val;

  val = my_xmalloc(sizeof(*val) * (my_strlen(opt) + 2));
  val = my_strcpy(val, opt);
  i = 0;
  while ((val[i] != '\0') && (val[i] != ' '))
    i++;
  val[i] = '=';
  return (val);
}

int     remplace_in_list(char *str, t_list *begin)
{
  while (begin != 0)
    {
      if (my_strncmp("PWD", begin->data, 3) == 0)
        {
	  begin->data = my_strcpy(begin->data, str);
          return (0);
        }
      begin = begin->next;
    }
  return (0);
}

void		add_elem_to_liste(char *arg, t_list **my_env)
{
  t_list	*new;

  new = my_xmalloc_v(sizeof(*new));
  if (arg != 0)
    {
      new->data = my_xmalloc(sizeof(*new->data) * (my_strlen(arg) + 1));
      new->data = my_strcpy(new->data, arg);
    }
  new->next = 0;
  new->prev = *my_env;
  if (*my_env)
    (*my_env)->next = new;
  *my_env = new;
}

char	*my_aff_param_list_opt(t_list *save)
{
  char	*val;
  int	i;
  int	j;

  i = 0;
  j = 0;
  val = my_xmalloc(sizeof(*val) * (my_strlen(save->data) + 1));
  while ((save->data[i] != '=') && (save->data[i] != '\0'))
    i++;
  if (save->data[i] == '=')
    i++;
  while (save->data[i] != '\0')
    val[j++] = save->data[i++];
  val[j] = '\0';
  return (val);
}

char		*my_aff_param_list(t_list *begin, char *str)
{
  t_list	*save;
  char		*val;

  if (begin != 0)
    while (begin->prev)
      begin = begin->prev;
  save = begin;
  while (save != 0)
    {
      if ((save->data != 0) && (my_strcmp2(str, save->data) == 0))
	{
	  val = my_aff_param_list_opt(save);
	  return (val);
	}
      save = save->next;
    }
  return (NULL);
}
