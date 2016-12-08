/*
** misc.c for  in /home/planch_j/rendu/CPE/marvin_planch_j/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun May 15 13:36:21 2016 Jean PLANCHER
** Last update Sun May 15 23:23:04 2016 Matteo Melis
*/

#include "rush.h"

int			find_comma(t_element *elem)
{
  t_element	*tmp;
  int		p;
  int		per;

  tmp = elem;
  per = 0;
  p = 0;
  while (tmp && !p)
    {
      if (tmp->token == PARENTHESIS && tmp->data[0] != 40 && !per)
	break ;
      if (tmp->token == PARENTHESIS)
	per += (tmp->data[0] == 40) * 2 - 1;
      if (tmp->token == COMMA && !per)
	{
	  printf(EA);
	  p = 1;
	}
      tmp->token = ELSE;
      tmp = tmp->next;
    }
  return (p);
}

t_element	*getntoken(t_list *list, int n, t_token token)
{
  t_element	*elem;

  elem = list->first;
  while (elem)
    {
      if ((unsigned int)elem->token == token)
	n--;
      if (n == 0)
	return (elem);
      elem = elem->next;
    }
  return (list->first);
}

static void	init_tok(char tok[11][2][256])
{
  strncpy(tok[0][1], M_CONST, 256);
  strncpy(tok[1][1], M_CHAR, 256);
  strncpy(tok[2][1], M_INT, 256);
  strncpy(tok[3][1], M_FLOAT, 256);
  strncpy(tok[4][1], M_SHORT, 256);
  strncpy(tok[5][1], M_SIGNED, 256);
  strncpy(tok[6][1], M_UNSIGNED, 256);
  strncpy(tok[7][1], M_STATIC, 256);
  strncpy(tok[8][1], M_REGISTER, 256);
  strncpy(tok[9][1], M_EXTERN, 256);
  strncpy(tok[10][1], M_VOID, 256);
  strncpy(tok[0][0], CONST, 256);
  strncpy(tok[1][0], CHAR, 256);
  strncpy(tok[2][0], INT, 256);
  strncpy(tok[3][0], FLOAT, 256);
  strncpy(tok[4][0], SHORT, 256);
  strncpy(tok[5][0], SIGNED, 256);
  strncpy(tok[6][0], UNSIGNED, 256);
  strncpy(tok[7][0], STATIC, 256);
  strncpy(tok[8][0], REGISTER, 256);
  strncpy(tok[9][0], EXTERN, 256);
  strncpy(tok[10][0], VOID, 256);
}

int	aff_token(char *str)
{
  char	tok[11][2][256];
  int	i;

  i = -1;
  init_tok(tok);
  while (++i < 11)
    {
      if (!strcmp(tok[i][0], str))
	return (printf(tok[i][1]));
    }
  return (printf(" %s", str));
}
