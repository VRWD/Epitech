/*
** put_av_in_tab.c for 42sh in /u/epitech_2013/algrin_t/public/42sh
** 
** Made by remi prsien-
** Login   <prsien_r@epitech.net>
** 
** Started on  Sun Jun 21 18:16:23 2009 remi prsien-
** Last update Sun Jun 21 20:11:17 2009 thibaut algrin
*/

#include "my_putstr.h"
#include "my_xmalloc.h"
#include "put_argv_in_tab.h"

void	put_av_in_tab(t_structs *str_tab, char *str)
{
  int	k;

  k = (sizeof(str_tab->tab[str_tab->n]) * (my_strlen(str) + 1));
  str_tab->tab[str_tab->n][str_tab->k] = str[str_tab->i];
  if (str[str_tab->i + 1] == '|' || (str[str_tab->i + 1] == '&')
      || (str[str_tab->i + 1] == ';'))
    str_tab->tab[str_tab->n][++str_tab->k] = str[++str_tab->i];
  str_tab->tab[++str_tab->n] = my_xmalloc(k);
  str_tab->k = 0;
  if (str[str_tab->i] == '|' && str[str_tab->i - 1] != '|')
    str_tab->tab[str_tab->n][str_tab->k++] = str[str_tab->i++];
}
