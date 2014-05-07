/*
** gest_err.c for 42sh in /u/all/algrin_t/cu/rendu/c/42sh
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Tue May 12 14:30:48 2009 thibaut algrin
** Last update Sun Jun 21 20:24:02 2009 thibaut algrin
*/

#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell.h"
#include "my_putstr.h"
#include "define.h"
#include "gest_err.h"

t_oper_err	tab_err[] = {
  {SIGBUS, BUS},
  {SIGSEGV, SEG},
  {SIGFPE, FLOAT},
  {0, 0}
};

void	gest_err(int status, t_struct *pile)
{
  int	i;

  if (WIFSIGNALED(status) == 1)
    {
      i = 0;
      while (tab_err[i].name != 0)
	{
	  if (WTERMSIG(status) == tab_err[i].name)
	    {
	      my_putstr(RED, 2);
	      my_putstr(tab_err[i].des, 2);
	      my_putstr(CANCEL, 2);
	    }
	  i++;
	}
    }
  if (WEXITSTATUS(status) == EXIT_FAILURE)
    {
      if (pile->seg[0] == OK)
	pile->e = NOT_OK;
      if (pile->seg[1] == OK)
	pile->e = OK;
    }
  if (WEXITSTATUS(status) == EXIT_SUCCESS)
    (pile->seg[1] == OK) ? pile->e = NOT_OK : 0;
}
