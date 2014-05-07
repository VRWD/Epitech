/*
** conf.h for 42sh in /u/all/stelle_t/cu/rendu/c/proj/42SH
** 
** Made by thomas stelletta
** Login   <stelle_t@epitech.net>
** 
** Started on  Tue May 12 11:22:35 2009 thomas stelletta
** Last update Wed Jun  3 11:22:06 2009 thibaut algrin
*/

#ifndef CONF_H_
# define CONF_H_

typedef	struct	s_tab_pro
{
  char		name;
  char		*res;
  char		*remp;
}		t_tab_pro;

void	aff_home(char *tmp2, t_struct *pile);
void	opt_prompt(char c, t_struct *pile);
int	fichier_conf(t_struct *pile);

#endif /* !CONF_H_ */
