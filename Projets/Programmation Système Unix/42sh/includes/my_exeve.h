/*
** my_exeve.h for 42sh in /u/all/stelle_t/cu/rendu/c/proj/42SH
** 
** Made by thomas stelletta
** Login   <stelle_t@epitech.net>
** 
** Started on  Tue May 12 12:01:13 2009 thomas stelletta
** Last update Tue May 26 15:27:28 2009 remi prsien-
*/

#ifndef MY_EXEVE_H_
# define MY_EXEVE_H_

int	my_strcmp(char *s1, char *s2);
int	check_com(char *path, char **com, t_struct *pile, char **my_env_tab);
int	my_execve2(char **tab, char **tab2, t_struct *pile, char **my_env_tab);
char	**my_list_in_tab(t_list *begin, char **my_env);
int	my_execve(char *tmp, char *opt, t_struct *pile);
int	gest_pipe(t_struct *pile);

#endif /* !MY_EXEVE_H_ */
