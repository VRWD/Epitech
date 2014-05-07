/*
** my_setenv.h for 42sh in /u/all/stelle_t/cu/rendu/c/proj/42SH
** 
** Made by thomas stelletta
** Login   <stelle_t@epitech.net>
** 
** Started on  Tue May 12 17:09:24 2009 thomas stelletta
** Last update Tue May 26 15:23:48 2009 remi prsien-
*/

#ifndef MY_SETENV_H_
# define MY_SETENV_H_

char	*parm_in_str(char *str, char *val, t_struct *pile, int flag);
int	check_setenv(char *opt, t_struct *pile);
int	my_setenv(char *opt, t_struct *pile);

#endif /* !MY_SETENV_H_ */
