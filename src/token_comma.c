/*
** token_comma.c for  in /home/melis_m/code/rendu/marvin_planch_j/src/
**
** Made by Matteo Melis
** Login   <melis_m@epitech.eu>
**
** Started on  Sun May 15 06:59:25 2016 Matteo Melis
** Last update Sun May 15 22:56:36 2016 Matteo Melis
*/

#include "rush.h"

int		parse_comma(char **str, t_list *list)
{
  char 		*dup;

  if ((*str)[0] == ',')
    {
      if (!(dup = strndup(*str, 1))
	  || add_end(&list, dup, COMMA))
	{
	  fprintf(stderr, "%s\n", MAL);
	  return (-1);
	}
      (*str)++;
      return (0);
    }
  return (1);
}
