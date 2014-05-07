/*
** mysh.h for 42sh in /u/all/stelle_t/cu/rendu/c/proj/42sh
** 
** Made by thomas stelletta
** Login   <stelle_t@epitech.net>
** 
** Started on  Sun May 17 14:50:18 2009 thomas stelletta
** Last update Tue May 26 15:23:46 2009 remi prsien-
*/

#ifndef MYSH_H_
# define MYSH_H_

int	count_pipe(char *str);
char	*put_space_in_str(char *str);
char	*reset(char *str, int nb);
void	initialisation(char *str, t_struct *pile);

#endif /* !MYSH_H_ */
