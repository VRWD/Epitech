/*
** my_setenv.c for 42sh in /u/epitech_2013/prsien_r/public/42/42FINAL
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Tue May 26 15:14:07 2009 thibaut algrin
** Last update Tue May 26 15:14:16 2009 thibaut algrin
*/

#include "minishell.h"
#include "my_xmalloc.h"
#include "my_putstr.h"
#include "my_strcat.h"
#include "my_strcmp.h"
#include "opt_liste_chaine.h"
#include "my_env.h"

char	*parm_in_str(char *str, char *val, t_struct *pile, int flag)
{
  char	*tmp;
  int	i;
  int	j;

  i = 1;
  j = 0;
  tmp = my_xmalloc(sizeof(*tmp) * (my_strlen(str) + my_strlen(val) + 1));
  while (str[i] != '\0')
    tmp[j++] = str[i++];
  str = my_aff_param_list(pile->my_env, tmp);
  if (flag == 0)
    str = my_strcat2(str, val, '=');
  else if (flag == 1)
    str = my_strcat2(val, str, '=');
  free(tmp);
  return (str);
}

int	check_setenv(char *opt, t_struct *pile)
{
  if (my_strcmp2(opt, pile->my_env->data) == 0)
    {
      free(pile->my_env->data);
      pile->my_env->data = remplacement(opt);
      return (0);
    }
  return (1);
}

int		my_setenv(char *opt, t_struct *pile)
{
  char	*str;

  if (*opt == 0)
    {
      my_env("", pile, "", "");
      return (0);
    }
  if ((pile->my_env != 0) && (opt != 0))
    while (pile->my_env->next != 0)
      {
	if (check_setenv(opt, pile) == 0)
	  return (0);
	pile->my_env = pile->my_env->next;
      }
  if ((pile->my_env != 0) && (check_setenv(opt, pile) == 0))
    return (0);
  str = remplacement(opt);
  add_elem_to_liste(str, &pile->my_env);
  free(str);
  return (0);
}
