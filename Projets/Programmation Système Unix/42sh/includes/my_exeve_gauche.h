/*
** my_exeve_gauche.h for 42sh in /u/all/stelle_t/cu/rendu/c/proj/42SH
** 
** Made by thomas stelletta
** Login   <stelle_t@epitech.net>
** 
** Started on  Tue May 12 12:17:23 2009 thomas stelletta
** Last update Thu Jun 11 09:43:17 2009 thibaut algrin
*/

#ifndef MY_EXEVE_GAUCHE_H_
# define MY_EXEVE_GAUCHE_H_

int	my_execve2_gauche(char **tab, char **tab2,
			  t_struct *pile, char **my_env_tab);
int	check_com_gauche(char **path, char **tab,
			 t_struct *pile, char **my_env_tab);
void	my_ex_gauche(t_struct *pile, char *str);
char	*extraction_keyword(char *str, int i, t_struct *pile);
int	my_exeve_gauche(char *str, t_struct *pile);

#endif /* !MY_EXEVE_GAUCHE_H_ */
