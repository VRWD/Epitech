/*
** mysh.c for mysh in /u/all/algrin_t/cu/rendu/c/minishell1bis
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Mon Jan 19 17:43:25 2009 thibaut algrin
** Last update Sun Jun 21 22:51:38 2009 thibaut algrin
*/

#include <stdlib.h>
#include "minishell.h"
#include "my_xmalloc.h"
#include "my_putstr.h"
#include "my_strcpy.h"
#include "my_strcat.h"
#include "extraction_com_opt.h"
#include "parseur_minishell.h"
#include "mysh.h"

int	count_pipe(char *str)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (str[i] != '\0')
    {
      if ((str[i] == ';') || (str[i] == '|')\
	  || (str[i] == '<') || (str[i] == '>'))
        n++;
      i++;
    }
  return (n);
}

int	check_space(char *str, int i, char *space, int j)
{
  if ((str[i] != ' ') && (str[i] != '|') && space[j - 1] != '<'
      && space[j - 1] != '>' && space[j - 1] != '&' && space[j - 1] != '|')
    return (OK);
  return (NOT_OK);
}

char    *put_space_in_str(char *str)
{
  int   i;
  char  *space;
  int	k;
  int   j;

  i = 0;
  j = 0;
  k = 3 * count_pipe(str);
  space = my_xmalloc(sizeof(*space) * (my_strlen(str) + k + 5));
  while (str[i] != '\0')
    {
      if ((i != 0) && ((str[i] == ';') || (str[i] == '|') || (str[i] == '<')
		       || (str[i] == '>') || str[i] == '&'))
        {
	  if (space[j - 1] != ' ' && space[j - 1] != '>'
	      && space[j - 1] != '<' && space[j - 1] != '&' && space[j - 1] != '|')
	    space[j++] = ' ';
          space[j++] = str[i++];
	  if (check_space(str, i, space, j) == OK)
	    space[j++] = ' ';
	}
      space[j++] = str[i++];
    }
  space[j] = '\0';
  return (space);
}

void	initialisation(char *str, t_struct *pile)
{
  char	*com;
  char	*tmp;
  char	*opt;

  tmp = my_xmalloc(sizeof(*tmp) * (my_strlen(str) + 3));
  tmp = my_strcpy(tmp, str);
  com = extraction_comande(tmp, com, pile);
  if ((opt = extraction_option(tmp, opt, pile)) == NULL)
    return ;
  free(tmp);
  if (com != NULL)
    {
      if (pile->flag_ddg != 1)
	parseur_minishell(com, opt, pile, str);
      free(com);
      if (opt != 0)
	free(opt);
    }
}
