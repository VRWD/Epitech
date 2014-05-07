/*
** my_redi_double_as.h for 42sh in /u/all/prsien_r/cu/public/42/42FINAL
** 
** Made by remi prsien-
** Login   <prsien_r@epitech.net>
** 
** Started on  Tue May 26 15:39:06 2009 remi prsien-
** Last update Tue May 26 15:40:46 2009 remi prsien-
*/

#ifndef MY_REDIR_DOUBLE_AS_H_
# define MY_REDIR_DOUBLE_AS_H_

void	my_extrc_left(char *tmp, char *opt, char *str);
void	my_free_ex(char **my_env_tab, char **path, char **act);
void	exe_left(t_struct *pile, char *str);
void	my_exe_left(t_struct *pile, char *str);
int	my_redi_left_double(char *opt, t_struct *pile, char *str, char *com);

#endif /* !MY_REDIR_DOUBLE_AS_H_ */
