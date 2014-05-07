/*
** check_str.c for 42sh in /u/all/algrin_t/cu/rendu/c/42sh
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Wed May 13 10:48:37 2009 thibaut algrin
** Last update Sun Jun 21 21:55:48 2009 thibaut algrin
*/

#include "minishell.h"
#include "my_putstr.h"
#include "define.h"

int	check_init(char *tmp)
{
  int	i;
  int	flag;

  i = 0;
  flag = 0;
  while (tmp[i] != '\0')
    {
      if ((tmp[i] == '\'') && (tmp[i + 1] != '"')
	&& (tmp[i - 1] != '"') && (tmp[i - 1] != '\\'))
	flag ^= 1;
      i++;
    }
  if (flag == 1)
    {
      my_putstr("Unmatched \'.\n", 2);
      return (NOT_OK);
    }
  return (OK);
}

int	check_init_2(char *tmp)
{
  int	i;
  int	flag;

  i = 0;
  flag = 0;
  while (tmp[i] != '\0')
    {
      if ((tmp[i] == '"'))
	{
	  if ((tmp[i - 1] != '\'') && (tmp[i + 1] != '\''))
	    flag ^= 1;
	  else if ((tmp[i - 1] == '\'') && (tmp[i - 2] == '\\'))
	    flag ^= 1;
	}
      i++;
    }
  if (flag == 1)
    {
      my_putstr("Unmatched \".\n", 2);
      return (NOT_OK);
    }
  return (OK);
}

int	second_check(int flag, char *str, int i)
{
  if ((flag == 1) && ((str[i] == '>') || (str[i] == '<') || (str[i] == '|')))
    return (OK);
  return (NOT_OK);
}

int	check_str(char *str, int i)
{
  int	flag_r;
  int	flag_p;

  flag_r = 0;
  flag_p = 0;
  while (str[i] != '\0')
    {
      if (flag_p == 0 && flag_r == 0 && str[i] == '|')
	flag_p = 1;
      else if (flag_r == 0 && flag_r == 0&& str[i] == '>')
	flag_r = 1;
      else if (flag_r == 1 && str[i] == '|')
	{
	  my_putstr(AMB, 2);
	  return (NOT_OK);
	}
      else if (flag_p == 1 && str[i] == '<')
	{
	  my_putstr(AMB, 2);
	  return (NOT_OK);
	}
      i++;
    }
  return (OK);
}

