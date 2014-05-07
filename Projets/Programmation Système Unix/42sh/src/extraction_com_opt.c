/*
** extraction_com_opt.c for 42sh in /u/all/algrin_t/cu/rendu/c/42sh
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Mon Jan 19 17:39:46 2009 thibaut algrin
** Last update Sun Jun 21 22:50:30 2009 thibaut algrin
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "minishell.h"
#include "xfonction.h"
#include "my_xmalloc.h"
#include "my_putstr.h"
#include "my_exeve_gauche.h"
#include "my_strcpy.h"
#include "extraction_com_opt.h"
#include "define.h"

char	*extraction_comande(char *str, char *com, t_struct *pile)
{
  int	i;
  int	y;

  i = 0;
  y = 0;
  if (str[i] == ' ')
    i++;
  if ((str[i] == '|') && (str[i + 1] != '|'))
    {
      i += 1;
      str = &str[i];
      pile->fd_g = pile->p[1];
      pile->flag_pipe = 0;
      my_xclose(pile->p[0]);
    }
  com = my_xmalloc(sizeof(*com) * (my_strlen(str) + 1));
  while ((str[i] != ' ') && (str[i] != '\0'))
    com[y++] = str[i++];
  com[y] = '\0';
  return (com);
}

int	check_double_quote(char *str, t_struct *pile)
{
  int	i;
  int	flag;

  i = 0;
  flag = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '"')
	flag ^= 1;
      i++;
    }
  if (pile->in == 1)
    return (NOT_OK);
  if (flag == 0)
    return (OK);
  return (NOT_OK);
}

int	check_opt(char *str, int i)
{
  if ((str[i] == ' ') &&
      (((str[i + 1] == '>') || (str[i + 1] == '<'))
       || (str[i + 1] == '|')|| (str[i + 1] == '\0')))
    return (OK);
  return (NOT_OK);
}

char	*ex_opt(char *str, int i, t_struct *pile, int *flag)
{
  int	n;
  char	*opt;

  n = 0;
  opt = my_xmalloc(sizeof(*opt) * (my_strlen(str) + 1));
  while (str[i] != '\0')
    {
      if ((pile->init == 0) && (str[i] == '"'))
	{
	  (check_double_quote(str, pile) == OK) ? i++ : 0;
	  *flag = 1;
	}
      ((str != NULL) && (check_opt(str, i) == OK)) ? i++ : 0;
      ((str[i] == '\\') && (str[i + 1] != '*') && (pile->in == 1)) ? i++ : 0;
      if (((str[i] == '<') || (str[i] == '>'))
	  && (str[i - 1] != '"') && (str[i - 1] != '\\'))
	break;
      if ((str[i] == '|') || (str[i] == ';') || str[i] == '&')
	break;
      if ((str[i] == ' ') && (str[i + 1] == ';'
			      || str[i + 1] == '|' || str[i + 1] == '&'))
	break;
      opt[n++] = str[i++];
    }
  return (opt);
}

char		*extraction_option(char *str, char *opt, t_struct *pile)
{
  int		flag;
  int		i;
  int		n;

  n = 0;
  i = 0;
  flag = 0;
  (str[i] == ' ') ? i++ : 0;
  pile->tmp = my_xmalloc(sizeof(*(pile->tmp)) * (my_strlen(str) + 1));
  pile->tmp = my_strcpy(pile->tmp, str);
  (str[i] == '|') ? i += 2 : 0;
  while ((str[i] != ' ') && (str[i] != '\0')
	 && (str[i] != '>') && (str[i] != '\\') && (str[i] != ';'))
    i++;
  if (str[i] != ';')
    i++;
  opt = ex_opt(str, i, pile, &flag);
  i += my_strlen(opt);
  if ((str[i] != '|') && (str[i] != '<') && (str[i] != '>')
      && (str[i] != '&') && str[i] != ';')
    i++;
  if ((str[i] == '>' && str[0] == '>') || (str[i] == '<' && str[0] == '<'))
    {
      my_putstr(AMB, 2);
      return (NULL);
    }
  pile->pos = i;
  if (flag == 0)
    my_redir_opt(str, i, pile);
  return (opt);
}
