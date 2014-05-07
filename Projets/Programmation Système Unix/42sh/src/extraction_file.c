/*
** extraction_file.c for 42sh in /u/all/algrin_t/cu/rendu/c/42sh
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Tue May 19 12:42:55 2009 thibaut algrin
** Last update Sun Jun 21 22:53:34 2009 thibaut algrin
*/

#include "minishell.h"
#include "extraction_file.h"
#include "my_xmalloc.h"
#include "my_putstr.h"
#include "redirection.h"
#include "define.h"

int	chek_after(char *str, int i, int flag, t_struct *pile)
{
  if (str[i] != '\0' && str[i + 1] == '|')
    pile->flag_pipe = 1;
  if ((flag != 1) && str[i] != '\0' && str[i + 1] == '>')
    redirection_droite(pile, str, i);
  else if (flag == 1 && str[i + 1] == '>')
    {
      my_putstr(AMB, 2);
      return (0);
    }
  else if (flag == 2 && str[i + 1] == '<')
    {
      my_putstr(AMB, 2);
      return (0);
    }
  return (1);
}

char	*extraction_file(char *str, int i, char *tmp, t_struct *pile)
{
  int	flag;
  int	k;

  k = 0;
  flag = 0;
  if (str[i - 1] == '>')
    flag = 1;
  if (str[i - 1] == '<')
    flag = 2;
  if (str[i] != '\0')
    i++;
  while ((str[i] == ' ') && (str[i] != ';') && (str[i] != '\0'))
    i++;
  tmp = NULL;
  if (str[i] != '\0')
    {
      tmp = my_xmalloc(sizeof(*tmp) * (my_strlen(str) + 1));
      while ((str[i] != '\0') && (str[i] != ';') && (str[i] != ' '))
	tmp[k++] = str[i++];
      tmp[k] = '\0';
      if (chek_after(str, i, flag, pile) == 0)
	return (NULL);
    }
  return (tmp);
}

char	*extraction_file_double(char *str, int i, char *tmp)
{
  int	k;

  k = 0;
  while ((str[i] == '>') || (str[i] == ' '))
    i++;
  tmp = NULL;
  if (str[i] != '\0')
    {
      tmp = my_xmalloc(sizeof(*tmp) * (my_strlen(str) + 1));
      while (str[i] != '\0' && str[i] != ' ')
	tmp[k++] = str[i++];
      tmp[k] = '\0';
      if (str[i] != '\0' && (str[i + 1] == '<' || str[i + 1] == '>'))
	{
	  my_putstr(AMB, 2);
	  return (0);
	}
    }
  return (tmp);
}
