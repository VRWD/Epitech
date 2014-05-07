/*
** my_env.h for 42sh in /u/all/stelle_t/cu/rendu/c/proj/42SH
** 
** Made by thomas stelletta
** Login   <stelle_t@epitech.net>
** 
** Started on  Tue May 12 11:53:28 2009 thomas stelletta
** Last update Tue May 26 15:23:50 2009 remi prsien-
*/

#ifndef MY_ENV_H_
# define MY_ENV_H_

void	my_env_opt(char *opt, t_struct *pile, char *str);
int	redi_opt(t_struct *pile);
int	my_env(char *opt, t_struct *pile, char *str, char *com);

#endif /* !MY_ENV_H_ */
