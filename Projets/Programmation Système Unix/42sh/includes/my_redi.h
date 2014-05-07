/*
** my_redi.h for 42sh in /u/all/stelle_t/cu/rendu/c/proj/42SH
** 
** Made by thomas stelletta
** Login   <stelle_t@epitech.net>
** 
** Started on  Tue May 12 13:50:39 2009 thomas stelletta
** Last update Tue May 26 15:27:30 2009 remi prsien-
*/

#ifndef MY_REDIR_H_
# define MY_REDIR_H_

void	extract_file_right(char *opt, char *file,
			   char *com_tmp, char *opt_tmp);
void	extract_file_left(char *opt, char *file, char *com_tmp, char *opt_tmp);
int	my_redir_right(char *opt, t_struct *pile, char *str, char *com);
int	my_redir_left(char *opt, t_struct *pile, char *str, char *com);

#endif /* !MY_REDIR_H_ */
