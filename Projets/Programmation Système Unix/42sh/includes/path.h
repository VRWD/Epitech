/*
** path.h for 42sh in /u/all/stelle_t/cu/rendu/c/proj/42sh
** 
** Made by thomas stelletta
** Login   <stelle_t@epitech.net>
** 
** Started on  Sun May 17 15:17:12 2009 thomas stelletta
** Last update Tue May 26 15:23:46 2009 remi prsien-
*/

#ifndef PATH_H_
# define PATH_H_

void	new_elem(char *arg, t_list **my_env);
char	*path(char *str, t_struct *pile);

#endif /* !PATH_H_ */
