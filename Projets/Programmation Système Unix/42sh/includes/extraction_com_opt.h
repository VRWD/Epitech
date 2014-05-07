/*
** extraction_com_opt.h for 42sh in /u/all/stelle_t/cu/rendu/c/proj/42sh
** 
** Made by thomas stelletta
** Login   <stelle_t@epitech.net>
** 
** Started on  Sun May 17 13:58:19 2009 thomas stelletta
** Last update Sat Jun 20 12:44:53 2009 thibaut algrin
*/

#ifndef EXTRACTION_COM_OPT_H_
# define EXTRACTION_COM_OPT_H_

char	*extraction_comande(char *str, char *com, t_struct *pile);
char	*extraction_file(char *str, int i, char *tmp, t_struct *pile);
char	*extraction_file_double(char *str, int i, char *tmp);
void	my_redir_opt(char *str, int i, t_struct *pile);
int	check_double_quote(char *str, t_struct *pile);
char	*extraction_option(char *str, char *opt, t_struct *pile);

#endif /* !EXTRACTION_COM_OPT_H_ */
