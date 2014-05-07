/*
** conf.h for 42sh in /u/all/stelle_t/cu/rendu/c/proj/42SH
** 
** Made by thomas stelletta
** Login   <stelle_t@epitech.net>
** 
** Started on  Tue May 12 11:22:35 2009 thomas stelletta
** Last update Sun Jun 21 20:56:54 2009 thibaut algrin
*/

#ifndef CONF_PROMPT_H_
# define CONF_PROMPT_H_

void	opt_p(char c, t_struct *pile);
void	extr_com_conf(char *str, char *com, char *opt);
void	par_prompt(char *tmp, t_struct *pile);
void	ctr_c(int k);
void	file_conf(char *str, int fd, t_struct *pile);

#endif /* !CONF_PROMT_H_ */
