/*
** my_redi_double.c for minishel in /u/all/algrin_t/cu/rendu/c/minishell2
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Mon Mar 23 13:52:21 2009 thibaut algrin
** Last update Tue May 26 16:45:59 2009 remi prsien-
*/

#include <fcntl.h>
#include "minishell.h"
#include "define.h"
#include "my_xmalloc.h"
#include "my_putstr.h"
#include "xfonction.h"
#include "my_redi_double.h"
#include "parseur_minishell.h"

char	*extrac_com_right_d(char *opt, char *opt_tmp)
{
  char	*com_tmp;
  int	j;
  int	i;

  i = 3;
  j = 0;
  com_tmp = my_xmalloc(sizeof(*com_tmp) * (my_strlen(opt) + 2));
  while ((opt[i] != ' ') && (opt[i] != '\0'))
    i++;
  i++;
  if (opt[i] != '\0')
    {
      while ((opt[i] != ' ') && (opt[i] != '\0'))
	com_tmp[j++] = opt[i++];
      com_tmp[j] = '\0';
      i++;
      j = 0;
      while (opt[i] != '\0')
	opt_tmp[j++] = opt[i++];
      opt_tmp[j] = '\0';
    }
  else
    com_tmp = NULL;
  return (com_tmp);
}

char	*extract_file_right_d(char *opt)
{
  int	i;
  int	j;
  char	*file;

  j = 0;
  i = 3;
  file = my_xmalloc(sizeof(*file) * (my_strlen(opt) + 2));
  if (opt[i] != '\0')
    {
      while ((opt[i] != ' ') && (opt[i] != '\0'))
	file[j++] = opt[i++];
      file[j] = '\0';
      j = 0;
      i++;
    }
  else
    file = NULL;
  return (file);
}

void	init_var(t_struct *pile, char *file)
{
  int	k;

  k = open(file, O_APPEND | O_RDWR | O_CREAT , 0777);
  if (k == -1)
    aff_err("open", 1);
  pile->red_dd = 0;
  pile->red_d = 0;
  if (k != -1)
    pile->fd = k;
}

int	my_redir_right_double(char *opt, t_struct *pile,
			      char *str, __attribute__((unused))char *com)
{
  int	i;
  int	j;
  char	*file;
  char	*com_tmp;
  char	*opt_tmp;

  i = 1;
  j = 0;
  file = extract_file_right_d(str);
  opt_tmp = my_xmalloc(sizeof(*opt_tmp) * (my_strlen(opt) + 1));
  com_tmp = extrac_com_right_d(str, opt_tmp);
  if ((file != NULL) && (com_tmp != NULL))
    {
      init_var(pile, file);
      free(file);
      parseur_minishell(com_tmp, opt_tmp, pile, str);
      free(com_tmp);
      free(opt_tmp);
    }
  else
    my_putstr(INV_COM, 2);
  return (0);
}

char	*extra_stop(char *str)
{
  int	j;
  int	i;
  char	*stop;

  i = 0;
  j = 0;
    stop = NULL;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  if (str[i] != '\0')
    {
      stop = my_xmalloc(sizeof(*stop) * (my_strlen(str) + 1));
      while ((str[i] != ' ') && (str[i] != '\0'))
	stop[j++] = str[i++];
      stop[j] = '\0';
      if (str[i] == '\0')
	{
	  my_putstr(INV_COM, 2);
	  return (NULL);
	}
    }
  if (str[i] == '\0')
    my_putstr(INV_COM, 2);
  return (stop);
}
