/*
** get_next_line.c for get_next_line in /u/all/algrin_t/cu/rendu/c/get_next_line
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Fri Dec 19 13:59:10 2008 thibaut algrin
** Last update Tue May 19 15:16:45 2009 thibaut algrin
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "get_next_line.h"

char	*my_strcpy2(char *dest, char *src2, t_structg *co)
{
  int	pos;
  int	count;

  pos = co->save;
  count = 0;
      while (count < co->count)
	{
	  dest[count] = src2[pos];
	  ++count;
	  ++pos;
	}
      dest[count] = '\0';
      return (dest);
}

char   	*my_strfcpy(char *dest, char *src1, char *src2, t_structg *co)
{
  int	count;
  int	save;

  count = 0;
  while (src1[count] != '\0')
    {
      dest[count] = src1[count];
      ++count;
    }
  save = count;
  count = 0;
  while (count < co->count)
    {
      dest[save] = src2[count];
      ++count;
      ++save;
    }
  dest[save] = '\0';
  return (dest);
}

char   	*grow_size(char *str, char *buffer, t_structg *co)
{
  char	*new_str;
  int	count;

  count = 0;
  if (str == NULL)
    count = 0;
  else
    while (str[count] != '\0')
      ++count;
  new_str = malloc(sizeof(*new_str) * (co->count + (count + 1)));
  if (new_str == NULL)
    {
      write(2, "Can't allocate Memory\n", 22);
      return (NULL);
    }
  if (str != NULL)
    new_str = my_strfcpy(new_str, str, buffer, co);
  else
    new_str = my_strcpy2(new_str, buffer, co);
  free(str);
  str = new_str;
  return (str);
}

int    	read_func(char *buffer, int *pos, int fd,
		  int nb_read, t_structg *co)
{
  if (fd == -1)
    {
      write(2, "Can't open the file or file not exit\n", 38);
      return (0);
    }
  if (nb_read == *pos)
    {
      nb_read = read(fd, buffer, BUFF_SIZE);
      if (nb_read == -1)
	{
	  write(2, "Can't read the file\n", 20);
	  return (0);
	}
      *pos  = 0;
      co->count = 0;
    }
  return (nb_read);
}

char		*get_next_line(const int fd)
{
  static char	buffer[BUFF_SIZE];
  static int   	nb_read = 0;
  static int	pos = 0;
  char		*str;
  t_structg	co;

  str = NULL;
  co.count = 0;
  if ((nb_read = read_func(buffer, &pos, fd, nb_read, &co)) == 0)
    return (NULL);
  co.save = pos;
  while (buffer[pos] != '\n' && co.count < BUFF_OUT)
    {
      ++pos;
      ++co.count;
      if (nb_read == pos || buffer[pos] == '\n' || co.count == BUFF_OUT)
	str = grow_size(str, buffer, &co);
      if ((nb_read = read_func(buffer, &pos, fd, nb_read, &co)) == 0)
      	return (str);
    }
  if (buffer[pos] == '\n' && co.count == 0)
    str = grow_size(str, buffer, &co);
  (buffer[pos] == '\n' ? ++pos : 0);
  return (str);
}
