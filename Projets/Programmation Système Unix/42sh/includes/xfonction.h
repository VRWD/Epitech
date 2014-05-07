/*
** xfonction.h for 42sh in /u/all/stelle_t/cu/rendu/c/proj/42sh
** 
** Made by thomas stelletta
** Login   <stelle_t@epitech.net>
** 
** Started on  Sun May 17 15:28:20 2009 thomas stelletta
** Last update Tue May 26 15:27:29 2009 remi prsien-
*/

#ifndef XFONCTION_H_
# define XFONCTION_H_

void	aff_err(char *str, int flag);
int	my_xchdir(char *here);
int	my_xpipe(int *p);
int	my_xdup2(int new_fd, int old_fd);
int	my_xclose(int fd);

#endif /* !XFONCTION_H_ */
