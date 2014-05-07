/*
** put_argv_in_tab.h for 42sh in /u/all/algrin_t/cu/rendu/c/42sh
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Thu May 21 15:45:19 2009 thibaut algrin
** Last update Sun Jun 21 18:30:49 2009 remi prsien-
*/

#ifndef PUT_ARGV_IN_TAB_H_
# define PUT_ARGV_IN_TAB_H_

typedef struct	s_structs
{
  int		i;
  int		n;
  int		k;
  char		**tab;
}		t_structs;

char	**put_argv_in_tab(char *str, t_structs *str_tab);

#endif /* !PUT_ARGV_IN_TAB_H_ */
