/*
** token_2.c for  in /home/melis_m/code/rendu/marvin_planch_j/src/
**
** Made by Matteo Melis
** Login   <melis_m@epitech.eu>
**
** Started on  Sat May 14 21:01:19 2016 Matteo Melis
** Last update Sun May 15 23:01:35 2016 Matteo Melis
*/

#include "rush.h"

int		parse_name(char **str, t_list *list)
{
  char		*save;
  char		*dup;

  save = *str;
  if (isdigit((*str)[0]))
    return (1);
  while (isalnum(**str) || **str == '_')
    (*str)++;
  if ((*str == save)
      || (**str != 0 && **str != '(' && **str != ',' && **str != '['
				   && **str != ')' && **str != ' '))
    return (1);
  if (!(dup = strndup(save, *str - save))
      || (add_end(&list, dup, NAME)))
    {
      fprintf(stderr, "%s\n", MAL);
      return (-1);
    }
  return (0);
}
