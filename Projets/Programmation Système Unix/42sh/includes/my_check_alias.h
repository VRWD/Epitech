/*
** my_check_alias.h for 42sh in /u/all/stelle_t/cu/rendu/c/proj/42SH
** 
** Made by thomas stelletta
** Login   <stelle_t@epitech.net>
** 
** Started on  Tue May 12 11:48:08 2009 thomas stelletta
** Last update Tue May 26 15:23:40 2009 remi prsien-
*/

#ifndef MY_CHECK_ALIAS_H_
# define MY_CHECK_ALIAS_H_

char	*my_alias_copy(char *str, char *com);
char	*my_check_list(t_struct *pile, char *com, char *opt);
char	*my_check_alias(char *str, t_struct *pile);
int	check_alias_loop(char *arg, t_struct *pile);

#endif /* !MY_CHECK_ALIAS_H_ */
