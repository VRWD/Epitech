/*
** check_dol_tild.h for 42sh in /u/all/stelle_t/cu/rendu/c/proj/42SH
** 
** Made by thomas stelletta
** Login   <stelle_t@epitech.net>
** 
** Started on  Tue May 12 11:22:10 2009 thomas stelletta
** Last update Tue May 26 16:54:37 2009 remi prsien-
*/

#ifndef CHECK_DOL_TILD_H_
# define CHECK_DOL_TILD_H_

typedef struct	s_var
{
  int		i;
  int		n;
  char		*opt;
}		t_var;

char	*check_dol_ext(char *str, int i);
char	*check_dol(char *str, t_struct *pile);
char	*check_tild(char *str, t_struct *pile);

#endif /* !CHECK_DOL_TILD_H_ */
