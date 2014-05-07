/*
** main.h for 42sh in /u/all/stelle_t/cu/rendu/c/proj/42sh
** 
** Made by thomas stelletta
** Login   <stelle_t@epitech.net>
** 
** Started on  Sun May 17 16:36:45 2009 thomas stelletta
** Last update Tue May 26 15:23:43 2009 remi prsien-
*/

#ifndef MAIN_H_
# define MAIN_H_

char	**put_argv_in_tab(char *str, t_struct *str_tab);
void	operation(char *tmp, t_struct *pile);
char	*catch_pwd(char *env, t_struct *pile);
void	mysh_param(char **env, t_struct *pile);
void	version(int argc, char **argv);
int	main(int argc, char **argv, char **env);

#endif /* !MAIN_H_ */
