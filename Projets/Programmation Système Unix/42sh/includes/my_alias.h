/*
** my_alias.h for 42sh in /u/all/stelle_t/cu/rendu/c/proj/42SH
** 
** Made by thomas stelletta
** Login   <stelle_t@epitech.net>
** 
** Started on  Tue May 12 11:36:31 2009 thomas stelletta
** Last update Tue May 26 15:23:43 2009 remi prsien-
*/

#ifndef MY_ALIAS_H_
# define MY_ALIAS_H_

void	add_elem_to_liste2(char *arg, char *arg2, t_list **my_env);
int	change_alias(t_struct *pile, char *com, char *val, int flag);
int	my_alias_compare(t_struct *pile, char *val, char *com);
void	my_alias_search(char *opt, char *com, t_struct *pile, int i);
int	my_alias(char *opt, t_struct *pile);

#endif /* !MY_ALIAS_H_ */
