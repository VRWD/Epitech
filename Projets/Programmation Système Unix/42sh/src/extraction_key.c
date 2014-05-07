/*
** extraction_key.c for 42sh in /u/epitech_2013/algrin_t/public/42sh
** 
** Made by remi prsien-
** Login   <prsien_r@epitech.net>
** 
** Started on  Sun Jun 21 18:55:56 2009 remi prsien-
** Last update Sun Jun 21 19:11:02 2009 remi prsien-
*/

#include <fcntl.h>
#include "minishell.h"
#include "my_xmalloc.h"
#include "my_putstr.h"
#include "xfonction.h"

void	extraction_key(char *str, int i, t_struct *pile)
{
  int	k;
  char	*tmp;

  if ((str[i] != '\0') && (str[i + 1] == '>'))
    {
      i++;
      if ((str[i] == '>') && (str[i + 1] == '>'))
        i += 3;
      else if ((str[i] == '>') && (str[i + 1] != '>'))
        i += 2;
      k = 0;
      tmp = my_xmalloc(sizeof(*tmp) * (my_strlen(str) + 1));
      while (str[i] != '\0')
        tmp[k++] = str[i++];
      pile->fd_exe = open(tmp, O_CREAT | O_RDWR | O_TRUNC, 0777);
      if (pile->fd == -1)
        {
          aff_err("open", 1);
          pile->fd = 1;
        }
    }
}
