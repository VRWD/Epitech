/*
** xfonction.c for 42sh in /u/epitech_2013/prsien_r/public/42/42FINAL
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Tue May 26 15:13:43 2009 thibaut algrin
** Last update Sun Jun 21 20:48:51 2009 thibaut algrin
*/

#include "minishell.h"
#include "define.h"
#include "my_putstr.h"
#include "xfonction.h"

void	aff_err(char *str, int flag)
{
  my_putstr(PROBLEME_WITH, 2);
  my_putstr(str, 2);
  my_putchar('\n', 2);
  if (flag == 0)
    exit(EXIT_FAILURE);
}

int	my_xchdir(char *here)
{
  if (chdir(here) == -1)
    {
      free(here);
      aff_err("chdir", 0);
    }
  return (0);
}

int	my_xpipe(int *p)
{
  int	k;

  k = pipe(p);
  if (k == -1)
    aff_err("pipe", 0);
  return (k);
}

int	my_xdup2(int new_fd, int old_fd)
{
  int	k;

  k = dup2(new_fd, old_fd);
  if (k == -1)
    aff_err("dup2", 0);
  return (k);
}

int	my_xclose(int fd)
{
  int	k;

  if (fd > 1)
    k = close(fd);
  if (k == -1)
    aff_err("close", 0);
  return (0);
}
