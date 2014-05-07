/*
** redirection.h for 42sh in /u/all/stelle_t/cu/rendu/c/proj/42sh
** 
** Made by thomas stelletta
** Login   <stelle_t@epitech.net>
** 
** Started on  Sun May 17 15:23:18 2009 thomas stelletta
** Last update Sun Jun 21 18:04:32 2009 remi prsien-
*/

#ifndef REDIRECTION_H_
# define REDIRECTION_H_

int	can_access(char *str, int i, int j);
int	redirection_droite(t_struct *pile, char *str, int i);
int	redirection_gauche(t_struct *pile, char *str, int i);
int	redirection_double_droite(t_struct *pile, char *str, int i);

void	my_redir_opt(char *str, int i, t_struct *pile);

#endif /* !REDIRECTION_H_ */
