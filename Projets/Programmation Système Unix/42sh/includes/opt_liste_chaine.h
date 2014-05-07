/*
** opt_liste_chaine.h for 42sh in /u/all/stelle_t/cu/rendu/c/proj/42sh
** 
** Made by thomas stelletta
** Login   <stelle_t@epitech.net>
** 
** Started on  Sun May 17 14:57:52 2009 thomas stelletta
** Last update Tue May 26 15:23:46 2009 remi prsien-
*/

#ifndef OPT_LISTE_CHAINE_H_
# define OPT_LISTE_CHAINE_H_

char	*remplacement(char *opt);
int	remplace_in_list(char *str, t_list *begin);
void	add_elem_to_liste(char *arg, t_list **my_env);
char	*my_aff_param_list_opt(t_list *save);
char	*my_aff_param_list(t_list *begin, char *str);

#endif /* !OPT_LISTE_CHAINE_H_ */
