/*
** error.c for  in /home/planch_j/rendu/CPE/marvin_planch_j/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri May 13 22:09:45 2016 Jean PLANCHER
** Last update Sun May 15 23:49:03 2016 Jean PLANCHER
*/

#include "rush.h"

void	error_line(char *str, int nb)
{
  fprintf(stderr, "%s\n", str);
  while (nb--)
    fprintf(stderr, " ");
  if (isatty(STDERR_FILENO))
    fprintf(stderr, "%s", "\033[1;31m");
  fprintf(stderr, "^\n");
  if (isatty(STDERR_FILENO))
    fprintf(stderr, "%s", "\033[0m");
}

int		show_error(t_list *list, t_element *elem)
{
  t_element	*tmp;
  int		len;

  len = 0;
  tmp = list->first;
  while (tmp != elem)
    {
      len += strlen(tmp->data) + 1;
      fprintf(stderr, "%s", tmp->data);
      if (tmp->token != PARENTHESIS && tmp->token != POINTER &&
	  tmp->token != COMMA && tmp->next)
	fprintf(stderr, " ");
      else
	len--;
      tmp = tmp->next;
    }
  if (elem && fprintf(stderr, "%s", tmp->data) && (len += strlen(elem->data)))
    while ((tmp = tmp->next) && fprintf(stderr, " %s", tmp->data));
  fprintf(stderr, "\n");
  while (len-- && fprintf(stderr, " "));
  if (isatty(STDERR_FILENO))
    fprintf(stderr, "%s", "\033[1;31m");
  if (fprintf(stderr, "^\n") && isatty(STDERR_FILENO))
    fprintf(stderr, "%s", "\033[0m");
  return (1);
}

static int	my_version(void)
{
  printf("marvin (EPITECH) 1.0 ");
  printf(VERSION);
  return (2);
}

static int	my_help(void)
{
  printf("Usage: marvin [EXPRESSION]\n");
  printf(HELP_D);
  printf(HELP_H);
  printf(HELP_V);
  return (my_version());
}

int	error(int ac, char *str)
{
  if (ac != 2)
    {
      printf(NB_P);
      return (1);
    }
  cut_space(str);
  cut_pv(str);
  if (!strcmp(str, "--help"))
    return (my_help());
  else if (!strcmp(str, "--version"))
    return (my_version());
  if (str[strlen(str) - 1] != ';')
    {
      fprintf(stderr, P_V);
      error_line(str, strlen(str));
      return (1);
    }
  else
    str[strlen(str) - 1] = 0;
  return (0);
}
