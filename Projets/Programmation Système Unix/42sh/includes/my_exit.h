/*
** my_exit.h for 42sh in /u/all/stelle_t/cu/rendu/c/proj/42SH
** 
** Made by thomas stelletta
** Login   <stelle_t@epitech.net>
** 
** Started on  Tue May 12 13:32:46 2009 thomas stelletta
** Last update Tue May 26 15:23:49 2009 remi prsien-
*/

#ifndef MY_EXIT_H_
# define MY_EXIT_H_

int	my_free_list(t_list *begin);
int	my_free_list_alias(t_list *begin);
void	aff_exit();
int	my_free_list_save_cd(t_list *begin);
int     my_exit(char *opt, t_struct *pile, char *str, char *com);

#endif /* MY_EXIT_H_ */
