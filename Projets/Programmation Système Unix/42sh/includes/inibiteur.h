/*
** inibiteur.h for 42sh in /u/all/stelle_t/cu/rendu/c/proj/42SH
** 
** Made by thomas stelletta
** Login   <stelle_t@epitech.net>
** 
** Started on  Tue May 12 11:34:48 2009 thomas stelletta
** Last update Tue May 26 16:56:58 2009 remi prsien-
*/

#ifndef INIBITEUR_H_
# define INIBITEUR_H_

typedef struct	s_var1
{
  int		i;
  int		j;
  int		k;
  char		*res;
}		t_var1;

void	ex_d_q(t_var1 *as, char *str);
void	ex_s_q(t_struct *pile, t_var1 *as, char *str);
char	*inibiteur(char *str, t_struct *pile);

#endif /* !INIBITEUR_H_ */
