/*
** access_control.c for 42sh in /u/epitech_2013/algrin_t/public/42sh
** 
** Made by thomas stelletta
** Login   <stelle_t@epitech.net>
** 
** Started on  Sat Jun 20 12:43:11 2009 thomas stelletta
** Last update Sat Jun 20 12:45:59 2009 thomas stelletta
*/

int	access_control()
{
  int	flag;
  int	k;

  flag = 0;
  if (can_access(tmp, 0, 0) == 1)
    return (NOT_OK);
  k = open(tmp, O_RDONLY);
  if (k == -1)
    {
      my_putstr("Access Denied", 2);
      flag = 1;
    }
  return (flag);
}
