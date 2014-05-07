/*
** get_next_line.h for get_next_line in /u/all/algrin_t/cu/rendu/c/get_next_line
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Fri Dec 19 14:00:01 2008 thibaut algrin
** Last update Tue May 26 15:23:44 2009 remi prsien-
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#  define BUFF_SIZE 4096
#  define BUFF_OUT 4096

typedef struct	s_struct_get
{
  int		nb_read;
  int		count;
  int		save;
}		t_structg;

char		*get_next_line(const int fd);

#endif /* GET_NEXT_LINE_H_ */
