/*
** aff_prompt.h for 42sh in /u/all/stelle_t/cu/rendu/c/proj/42SH
** 
** Made by thomas stelletta
** Login   <stelle_t@epitech.net>
** 
** Started on  Tue May 12 11:22:00 2009 thomas stelletta
** Last update Tue May 26 15:56:08 2009 remi prsien-
*/

#ifndef AFF_PROMPT_H_
# define AFF_PROMPT_H_

void	init_variable(t_struct *pile);
char	*gere_var(t_struct *pile, char *str);
void	aff_prompt(t_struct *pile);

#endif /* !AFF_PROMPT_H_ */
