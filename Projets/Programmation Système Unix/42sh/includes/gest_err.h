/*
** gest_err.h for 42sh in /u/all/stelle_t/cu/rendu/c/proj/42sh
** 
** Made by thomas stelletta
** Login   <stelle_t@epitech.net>
** 
** Started on  Sun May 17 14:15:08 2009 thomas stelletta
** Last update Tue May 26 16:55:40 2009 remi prsien-
*/

#ifndef GEST_ERR_H_
# define GEST_ERR_H_

typedef	struct	s_oper_err
{
  int		name;
  char		*des;
}		t_oper_err;

void	gest_err(int status, t_struct *pile);

#endif /* !GEST_ERR_H_ */
