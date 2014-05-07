/*
** my_cd_opdir.h for 42sh in /u/epitech_2013/algrin_t/public/42sh
** 
** Made by remi prsien-
** Login   <prsien_r@epitech.net>
** 
** Started on  Sun Jun 21 19:38:14 2009 remi prsien-
** Last update Sun Jun 21 19:50:23 2009 remi prsien-
*/

#ifndef MY_CD_OPDIR_H_
# define MY_CD_OPDIR_H_

typedef struct	my_list
{
  char		*pwd;
  char		*path;
  int		n;
}		a_list;

int	my_cd_opdir(a_list *ab, char *str, int flag, t_struct *pile);

#endif /* !MY_CD_OPDIR_H_ */
