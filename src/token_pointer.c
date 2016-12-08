/*
** token_pointer.c for  in /home/melis_m/code/rendu/marvin_planch_j/src/
**
** Made by Matteo Melis
** Login   <melis_m@epitech.eu>
**
** Started on  Sun May 15 07:00:29 2016 Matteo Melis
** Last update Sun May 15 22:57:27 2016 Matteo Melis
*/

#include "rush.h"

static int	star_ptr_case(char **str, t_list *list)
{
  char		*dup;

  if (**str == '*')
    {
      (*str)++;
      if (!((dup = strdup("*")))
	  || (add_end(&list, dup, POINTER)))
	{
	  fprintf(stderr, "%s\n", MAL);
	  return (-1);
	}
      return (0);
    }
  return (1);
}

static int	closing_bracket(char **str, char *save)
{
  if (**str == ']')
    {
      fprintf(stderr, "%s\n", "Unexpected bracket.");
      error_line(save, *str - save);
      return (1);
    }
  return (0);
}

static int	go_to_closing_bracket(char **str)
{
  while (**str != ']')
    {
      (*str)++;
      if (**str == 0)
	{
	  fprintf(stderr, "%s\n", UNX_BRACKET);
	  return (-1);
	}
    }
  return (0);
}

static int 	brackets_ptr_case(char **str, t_list *list)
{
  char		*dup;
  char		*save;

  save = *str;
  if (closing_bracket(str, save) == 1)
    return (1);
  if (**str == '[')
    {
      if (go_to_closing_bracket(str) == -1)
	return (-1);
      (*str)++;
      if (!(dup = strndup(save, *str - save))
	  || (add_end(&list, dup, POINTER)))
	{
	  fprintf(stderr, "%s\n", MAL);
	  return (-1);
	}
      return (0);
    }
  return (1);
}

int 		parse_pointer(char **str, t_list *list)
{
  if (star_ptr_case(str, list) == 0
      || brackets_ptr_case(str, list) == 0)
    return (0);
  return (1);
}
