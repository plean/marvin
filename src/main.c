/*
** main.c for  in /home/planch_j/rendu/CPE/marvin_planch_j/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri May 13 21:24:37 2016 Jean PLANCHER
** Last update Sun May 15 18:29:50 2016 Jean PLANCHER
*/

#include "rush.h"

int		main(int ac, char *const *av)
{
  char ATC_TAB	**tab;
  t_list	*list;
  int		i;

  tab = NULL;
  list = NULL;
  if ((i = error(ac, av[1])))
    return (1);
  if (i == 2)
    return (0);
  if ((tab = my_str_to_tab(av[1], ';', ';')) == NULL)
    {
      printf(MAL);
      return (1);
    }
  i = -1;
  while (tab[++i] && !lexer(&list, tab[i]))
    marvin(list);
  return (0);
}
