/*
** errors_expression.c for  in /home/planch_j/rendu/CPE/marvin_planch_j/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun May 15 04:20:01 2016 Jean PLANCHER
** Last update Sun May 15 07:00:27 2016 Jean PLANCHER
*/

#include "rush.h"

static int	test_prefix(t_list *list)
{
  t_element	*elem;
  int		k;

  k = 0;
  elem = list->first;
  while (elem)
    {
      if (elem->token == PREFIX)
	k++;
      if (k > 1)
	{
	  fprintf(stderr, TP1);
	  return (1);
	}
      elem = elem->next;
    }
  return (0);
}

static int	test_pointer(t_list *list)
{
  t_element	*elem;
  int		k;
  int		p;

  k = 0;
  p = 0;
  elem = list->first;
  while (elem)
    {
      if (elem->token == POINTER)
	{
	  k++;
	  if ((elem->data[0] == '*' && p) || (elem->data[0] == '[' && !p))
	    {
	      fprintf(stderr, TP2);
	      return (k);
	    }
	}
      else if (elem->token == NAME)
	p = 1;
      else if (elem->token == COMMA || elem->token == PARENTHESIS)
	p = 0;
      elem = elem->next;
    }
  return (0);
}

static int	test_type(t_list *list)
{
  t_element	*elem;
  int		k;
  int		p;

  k = 0;
  p = 0;
  elem = list->first;
  while (elem)
    {
      if (elem->token == TYPE)
	{
	  k++;
	  if (p)
	    {
	      fprintf(stderr, TT);
	      return (k);
	    }
	  if (elem->next && elem->next->token != TYPE &&
	      elem->next->token != CONST_VOLATILE)
	    p = 1;
	}
      p = (elem->token == COMMA || elem->token == PARENTHESIS) ? 0 : p;
      elem = elem->next;
    }
  return (0);
}

int	errors_expression(t_list *list)
{
  int	k;

  if (test_prefix(list))
    return (show_error(list, getntoken(list, 2, PREFIX)));
  if ((k = test_type(list)))
    return (show_error(list, getntoken(list, k, TYPE)));
  if  ((k = test_pointer(list)))
    return (show_error(list, getntoken(list, k, POINTER)));
  return (0);
}
