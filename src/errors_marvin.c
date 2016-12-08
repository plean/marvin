/*
** errors_marvin.c for  in /home/planch_j/rendu/CPE/marvin_planch_j/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sat May 14 15:09:35 2016 Jean PLANCHER
** Last update Sun May 15 23:12:26 2016 Jean PLANCHER
*/

#include "rush.h"

static int	check_var(t_element *elem, int *var, int f)
{
  if (elem->token == TYPE || elem->token == CONST_VOLATILE ||
      elem->token == PREFIX)
    {
      fprintf(stderr, ED);
      return (1);
    }
  if ((elem->token == PARENTHESIS && elem->data[0] == 40) ||
       (elem->token == COMMA && f))
    *var = 1;
  return (0);
}

static int	check_type(t_element *elem, int *type)
{
  if (elem->token == COMMA || elem->token == PREFIX)
    {
      fprintf(stderr, MI);
      return (1);
    }
  if (elem->token == NAME)
    *type = 1;
  return (0);
}

static int	check_dec(t_element *elem, int *dec, int *type)
{
  if (elem->token == COMMA)
    {
      fprintf(stderr, MI);
      return (1);
    }
  if (elem->token == TYPE)
    {
      *dec = 1;
      if (elem->next && !strcmp(elem->data, "void"))
	*type = 1;
    }
  return (0);
}

int		check_errors(t_list *list)
{
  t_element	*elem;
  int		dec;
  int		var;
  int		type;
  int		f;

  f = dec = var = type = 0;
  elem = list->first;
  while (elem && elem->token != COMMA)
    {
      if ((dec && type && check_var(elem, &var, f)) ||
	  (dec && !type && check_type(elem, &type)) ||
	  (!dec && !type && check_dec(elem, &dec, &type)))
	return (show_error(list, elem));
      if (var && (f = 1))
	type = var = dec = 0;
      elem = elem->next;
    }
  if (!type)
    {
      fprintf(stderr, ED);
      return (show_error(list, elem));
    }
  return (0);
}
