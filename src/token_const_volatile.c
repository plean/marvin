/*
** token_const_volatile.c for  in /home/melis_m/code/rendu/marvin_planch_j/src/
**
** Made by Matteo Melis
** Login   <melis_m@epitech.eu>
**
** Started on  Sun May 15 07:00:16 2016 Matteo Melis
** Last update Sun May 15 22:56:57 2016 Matteo Melis
*/

#include "rush.h"

int		parse_const_volatile(char **str, t_list *list)
{
  char		*dup;

  if (!strncmp(*str, "const", 5) && !isalnum((*str)[5]))
    {
      if (!(dup = strndup(*str, 5))
	  || add_end(&list, dup, CONST_VOLATILE))
	return (-1);
      *str += 5;
      return (0);
    }
  else if (!strncmp(*str, "volatile", 8) && !isalnum(*(str + 8)))
    {
      if (!(dup = strndup(*str, 8))
	  || add_end(&list, dup, CONST_VOLATILE))
	return (-1);
      *str += 8;
      return (0);
    }
  return (1);
}
