/*
** my_show_tab.c for my_show_tab in /u/all/algrin_t/cu/tmp
** 
** Made by thibaut algrin
** Login   <algrin_t@epitech.net>
** 
** Started on  Tue Dec 30 12:01:23 2008 thibaut algrin
** Last update Thu Feb 26 13:12:39 2009 thibaut algrin
*/

void	my_show_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != 0)
    {
      my_putstr(tab[i], 1);
      if (tab[i + 1] != 0)
	my_putchar('\n', 1);
      i++;
    }
}
