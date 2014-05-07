/*
** my_redi.c for 42sh in /u/all/algrin_t/cu/rendu/c/minishell2
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Sun Mar 22 13:01:30 2009 thibaut algrin
** Last update Sun Jun 21 22:40:25 2009 thibaut algrin
*/

#include <fcntl.h>
#include "minishell.h"
#include "define.h"
#include "my_putstr.h"
#include "my_xmalloc.h"
#include "xfonction.h"
#include "my_redi.h"
#include "parseur_minishell.h"

void	extract_file_right(char *opt, char *file, char *com_tmp, char *opt_tmp)
{
  int	i;
  int	j;

  j = 0;
  i = 1;
  while ((opt[i] != ' ') && (opt[i] != '\0'))
    file[j++] = opt[i++];
  file[j] = '\0';
  j = 0;
  i++;
  if (opt[i] != '\0')
    {
      while ((opt[i] != '\0') && (opt[i] != ' '))
	com_tmp[j++] = opt[i++];
      com_tmp[j] = '\0';
      i++;
    }
  else
    {
      my_putstr(INV_COM, 2);
      com_tmp = NULL;
    }
  j = 0;
  while (opt[i] != '\0' && opt[i] != '<' && opt[i] != '>')
    opt_tmp[j++] = opt[i++];
}

void	extract_file_left(char *opt, char *file, char *com_tmp, char *opt_tmp)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while ((opt[i] != ' ') && (opt[i] != '\0'))
    file[j++] = opt[i++];
  file[j] = '\0';
  j = 0;
  i++;
  if (opt[i] != '\0')
    while ((opt[i] != '\0') && (opt[i] != ' '))
      com_tmp[j++] = opt[i++];
  else
    {
      my_putstr(INV_COM, 2);
      com_tmp = NULL;
    }
  i++;
  j = 0;
  while (opt[i] != '\0')
    opt_tmp[j++] = opt[i++];
  opt_tmp[j] = '\0';
}

int	check_fd(int fd)
{
  if (fd == -1)
    {
      aff_err("open", 1);
      return (NOT_OK);
    }
  return (OK);
}

int	my_redir_right(char *opt, t_struct *pile,
		       char *str, __attribute__((unused))char *com)
{
  int	i;
  int	j;
  int	k;
  char	*file;
  char	*com_tmp;
  char	*opt_tmp;

  i = 1;
  j = 0;
  file = my_xmalloc(sizeof(*file) * (my_strlen(opt) + 1));
  com_tmp = my_xmalloc(sizeof(*com_tmp) * (my_strlen(opt) + 1));
  opt_tmp = my_xmalloc(sizeof(*opt_tmp) * (my_strlen(opt) + 1));
  extract_file_right(opt, file, com_tmp, opt_tmp);
  if (*com_tmp == 0)
    return (0);
  k = open(file, O_CREAT | O_RDWR | O_TRUNC, 0777);
  if (check_fd(k) == NOT_OK)
    return (0);
  pile->red_d = 0;
  (k != -1) ? pile->fd = k : 0;
  free(file);
  parseur_minishell(com_tmp, opt_tmp, pile, str);
  free(com_tmp);
  free(opt_tmp);
  return (0);
}

int	my_redir_left(char *opt, t_struct *pile,
		      char *str, __attribute__((unused))char *com)
{
  int	i;
  int	j;
  int	k;
  char	*file;
  char	*com_tmp;
  char	*opt_tmp;

  i = 1;
  j = 0;
  file = my_xmalloc(sizeof(*file) * (my_strlen(opt) + 1));
  com_tmp = my_xmalloc(sizeof(*com_tmp) * (my_strlen(opt) + 1));
  opt_tmp = my_xmalloc(sizeof(*opt_tmp) * (my_strlen(opt) + 1));
  extract_file_left(opt, file, com_tmp, opt_tmp);
  if (*com_tmp == 0)
    return (0);
  k = open(file, O_RDONLY);
  if (check_fd(k) == NOT_OK)
    return (0);
  pile->red_g = 0;
  pile->fd_g = k;
  free(file);
  parseur_minishell(com_tmp, opt_tmp, pile, str);
  free(com_tmp);
  free(opt_tmp);
  return (0);
}
