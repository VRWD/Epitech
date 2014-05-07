/*
** my_putstr.h for my_putstr.h in /u/all/stelle_t/cu/rendu/c/proj/42SH
** 
** Made by thomas stelletta
** Login   <stelle_t@epitech.net>
** 
** Started on  Tue May 12 13:47:53 2009 thomas stelletta
** Last update Sun Jun 21 21:43:22 2009 thibaut algrin
*/

#ifndef MY_PUTSTR_H_
# define MY_PUTSTR_H_

void	my_putchar(char c, int fd);
int	my_putstr(char *str, int fd);
int	my_putstr2(char *str, int i, int fd);
int	my_putstr_to_c(char *str, char c, int fd);
int	my_strlen(char *str);
void	my_put_nbr(int nb, int fd);

#endif /* !MY_PUTSTR_H_ */
