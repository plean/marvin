/*
** aff_mess.c for  in /home/planch_j/rendu/CPE/marvin_planch_j/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sat May 14 23:18:40 2016 Jean PLANCHER
** Last update Sun May 15 23:32:25 2016 Matteo Melis
*/

#include "rush.h"

void		aff_var(t_element *elem)
{
  t_element	*tmp;

  printf(VAR);
  tmp = elem;
  while (tmp && tmp->token != PARENTHESIS &&
	 tmp->token != 41 && tmp->token != NAME)
    {
      if (tmp->token == CONST_VOLATILE || tmp->token == PREFIX)
	aff_token(tmp->data);
      if (tmp->token == POINTER)
	printf(M_POINTER);
      tmp = tmp->next;
    }
  while (tmp && (tmp = tmp->next) && tmp->token == POINTER)
    printf(M_ARRAY);
  tmp = elem;
  while (tmp && tmp->token != NAME && tmp->token != COMMA &&
	 tmp->token != PARENTHESIS && tmp->token != 41)
    {
      if (tmp->token == TYPE)
	aff_token(tmp->data);
      tmp = tmp->next;
    }
  if (tmp && tmp->token == NAME && printf(NM))
    aff_token(tmp->data);
}

void		aff_func(t_element *elem)
{
  t_element	*tmp;

  tmp = elem;
  printf(FUN);
  while (tmp && tmp->token != NAME && (tmp = tmp->next));
  aff_token(tmp->data);
  printf(F_PAR);
  while (tmp->token != PARENTHESIS && (tmp = tmp->next));
  while (aff_vf(tmp->next) && find_comma(tmp->next));
  printf(R_ENV);
  tmp = elem;
  while (tmp && tmp->token != NAME)
    {
      if (tmp->token == POINTER)
	printf(M_POINTER);
      else if (tmp->token == CONST_VOLATILE || tmp->token == PREFIX)
	aff_token(tmp->data);
      tmp = tmp->next;
    }
  tmp = elem;
  while (tmp && tmp->token != NAME &&
	 ((tmp->token == TYPE && aff_token(tmp->data)) || tmp->token))
    tmp = tmp->next;
}

static t_element	*get_lpar(t_element *elem)
{
  t_element		*tmp;
  int			k;
  int			per;

  k = 0;
  per = 0;
  tmp = elem;
  while (tmp)
    {
      if (!per && tmp->token == PARENTHESIS && tmp->data[0] == 40)
	k++;
      if (tmp->token == PARENTHESIS)
	per += (tmp->data[0] == 40) * 2 - 1;
      if (k == 2)
	return (tmp);
      tmp = tmp->next;
    }

  return (elem);
}

static void	aff_pfunc2(t_element *elem, t_element *tmp)
{
  if (tmp && tmp->next && tmp->next->next && tmp->next->next->token ==
      PARENTHESIS && tmp->next->next->data[0] == 40)
    {
      printf(PF_PARAM3);
      while (tmp && tmp->token != PARENTHESIS && tmp->data[0] != 40)
	tmp = tmp->next;
      tmp = get_lpar(elem);
      while (aff_vf(tmp->next) && find_comma(tmp->next));
      printf(R_ENV);
    }
  tmp = elem;
  while (tmp && tmp->token != NAME)
    {
      if (tmp->token == TYPE || tmp->token == PREFIX)
	aff_token(tmp->data);
      tmp = tmp->next;
    }
}

void		aff_pfunc(t_element *elem)
{
  t_element	*tmp;

  tmp = elem;
  printf(PFUN);
  while (tmp && tmp->token != NAME)
    {
      if (tmp->token == POINTER)
	tmp->token = ELSE;
      if (tmp->token == CONST_VOLATILE)
	aff_token(tmp->data);
      tmp = tmp->next;
    }
  if (tmp)
    aff_token(tmp->data);
  if (tmp && (tmp = tmp->next) && tmp->token == POINTER && (tmp = tmp->next))
    printf(M_ARRAY);
  printf(PF_PARAM1);
  while (tmp && tmp->token == PARENTHESIS && (tmp = tmp->next));
  while (aff_vf(tmp) && find_comma(tmp));
  printf(PF_PARAM2);
  while (tmp && tmp->token != PARENTHESIS && (tmp = tmp->next));
  aff_pfunc2(elem, tmp);
}
