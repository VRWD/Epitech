/*
** my_put_nbr.c for 42sh in /u/all/algrin_t/cu/public/42sh
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Sun Jun 21 19:53:17 2009 thibaut algrin
** Last update Sun Jun 21 20:07:58 2009 thibaut algrin
*/

#include "my_putstr.h"

void	my_put_nbr(int nb, int fd)
{
  int   quot;

  quot = 1;
  if (nb < 0)
    {
      nb = nb * (-1);
      my_putchar('-', fd);
    }
  while ((nb / quot) >= 10)
    {
      quot = quot * 10;
    }
  while (quot != 0)
    {
      my_putchar((nb / quot) % 10 + '0', fd);
      quot = quot / 10;
    }
}
