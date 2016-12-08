/*
** marvin.c for  in /home/planch_j/rendu/CPE/marvin_planch_j/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sat May 14 08:01:49 2016 Jean PLANCHER
** Last update Sun May 15 23:21:09 2016 Matteo Melis
*/

#include "rush.h"

static int	is_vf(t_element *elem)
{
  t_element	*tmp;
  int		t;
  int		z;

  t = 0;
  z = 0;
  tmp = elem;
  while (tmp && tmp->token != COMMA)
    {
      if (!t && tmp->token == PARENTHESIS)
	{
	  if (tmp->data[0] == 40)
	      z++;
	  else
	    return (z);
	}
      if (tmp->token == PARENTHESIS)
	t += (tmp->data[0] == 40) * 2 - 1;
      tmp = tmp->next;
    }
 return (z);
}

static int	nb_c(t_element *elem)
{
  int		nbc;
  int		per;

  nbc = 0;
  per = 0;
  while (elem)
    {
      if (elem->token == PARENTHESIS)
	per += (elem->data[0] == 40) * 2 - 1;
      if (elem->token == COMMA && !per)
	nbc++;
      elem = elem->next;
    }
  return (nbc);
}

static void	sup_to_comma(t_element *elem)
{
  int		per;

  per = 0;
  while (elem && elem->token != COMMA)
    {
      if (elem->token == PARENTHESIS)
	per += (elem->data[0] == 40) * 2 - 1;
      if (elem->token == NAME || elem->token == POINTER ||
	  elem->token == CONST_VOLATILE || elem->token == PARENTHESIS ||
	  (elem->token == TYPE && per))
	elem->token = ELSE;
      elem = elem->next;
    }
  elem->token = ELSE;
}

int	aff_vf(t_element *elem)
{
  int		vf;

  if (!elem || elem->token == PARENTHESIS)
    {
      printf(VAR " void");
      return (1);
    }
  vf = is_vf(elem);
  (!vf) ? aff_var(elem) : (vf == 1) ? aff_func(elem) : aff_pfunc(elem);
  return (1);
}

void		marvin(t_list *list)
{
  int		nbc;

  nbc = nb_c(list->first);
  if (check_errors(list) ||
      errors_expression(list))
    {
      del_list(&list);
      return ;
    }
  printf(DECL);
  while (nbc-- > 0)
    {
      aff_vf(list->first);
      sup_to_comma(list->first);
      printf(EA);
      fflush(stdout);
    }
  aff_vf(list->first);
  printf("\n");
  del_list(&list);
}
