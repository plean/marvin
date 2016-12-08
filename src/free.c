/*
** free.c for  in /home/planch_j/rendu/CPE/marvin_planch_j/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sat May 14 06:45:00 2016 Jean PLANCHER
** Last update Sat May 14 09:27:32 2016 Jean PLANCHER
*/

#include "rush.h"

void	free_tab(char ***to_free)
{
  int   i;

  if (*to_free == NULL)
    return ;
  i = -1;
  while ((*to_free)[++i])
    free((*to_free)[i]);
  free(*to_free);
}
