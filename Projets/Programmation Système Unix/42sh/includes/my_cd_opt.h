/*
** my_cd_opt.h for 42sh in /u/epitech_2013/algrin_t/public/42sh
** 
** Made by remi prsien-
** Login   <prsien_r@epitech.net>
** 
** Started on  Sat Jun 20 12:23:28 2009 remi prsien-
** Last update Sun Jun 21 20:25:51 2009 thibaut algrin
*/

#ifndef MY_CD_OPT_H_
# define MY_CD_OPT_H_

int	my_cd_back(t_struct *pile, int flag);
void	my_cd_null(t_struct *pile, int flag);
int	my_cd_opendir(char *str, t_struct *pile, int flag);
int	my_cd_minus(__attribute__((unused))char *str, t_struct *pile);

#endif /* !MY_CD_OPT_H_ */
