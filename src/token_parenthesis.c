/*
** token.c for  in /home/melis_m/code/rendu/marvin_planch_j/src/
**
** Made by Matteo Melis
** Login   <melis_m@epitech.eu>
**
** Started on  Sat May 14 15:39:03 2016 Matteo Melis
** Last update Sun May 15 22:57:21 2016 Matteo Melis
*/

#include "rush.h"

int		parse_parenthesis(char **str, t_list *list)
{
  char		*dup;

  if (**str == '(' || **str == ')')
    {
      if (!(dup = strndup(*str, 1))
	  || (add_end(&list, dup, PARENTHESIS)))
	{
	  fprintf(stderr, "%s\n", MAL);
	  return (-1);
	}
      (*str)++;
      return (0);
    }
  return (1);
}
