/*
** my_str_in_tabbis.h for 42sh in /u/all/stelle_t/cu/rendu/c/proj/42SH
** 
** Made by thomas stelletta
** Login   <stelle_t@epitech.net>
** 
** Started on  Tue May 12 17:31:01 2009 thomas stelletta
** Last update Tue May 26 15:23:48 2009 remi prsien-
*/

#ifndef MY_STR_IN_TABBIS_H_
# define MY_STR_IN_TABBIS_H_

void	sup(char **tab, int n, char *opt);
void	annexe(char *str, char **tab, int i, char *opt);
char	**my_str_in_tab(char *str, char *opt);
void	annexe2(char *str, int n, char **tab);
char	**my_str_in_tab2(char *opt, char *tmp);

#endif /* !MY_STR_IN_TABBIS_H_ */
