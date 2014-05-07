/*
** parseur_minishell.h for 42sh in /u/all/stelle_t/cu/rendu/c/proj/42sh
** 
** Made by thomas stelletta
** Login   <stelle_t@epitech.net>
** 
** Started on  Sun May 17 15:08:33 2009 thomas stelletta
** Last update Tue May 26 16:53:45 2009 remi prsien-
*/

#ifndef PARSEUR_MINISHELL_H_
# define PARSEUR_MINISHELL_H_

typedef struct s_opers
{
  char          *opers;
  int           (*f)();
}               t_opers;

int	my_version(char *opt, t_struct *pile);
int	parseur_minishell_opt(char *com, char *opt, t_struct *pile);
int	parseur_minishell(char *com, char *opt, t_struct *pile, char *str);

#endif /* !PARSEUR_MINISHELL_H_ */
