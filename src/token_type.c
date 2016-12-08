/*
** token.c for  in /home/melis_m/code/rendu/marvin_planch_j/src/
**
** Made by Matteo Melis
** Login   <melis_m@epitech.eu>
**
** Started on  Sat May 14 15:39:03 2016 Matteo Melis
** Last update Sun May 15 22:57:42 2016 Matteo Melis
*/

#include "rush.h"

static void	init_tab(char *types[10])
{
  types[0] = "void";
  types[1] = "char";
  types[2] = "int";
  types[3] = "float";
  types[4] = "double";
  types[5] = "short";
  types[6] = "long";
  types[7] = "signed";
  types[8] = "unsigned";
  types[9] = NULL;
}

static int 	first_case(char **str, t_list *list)
{
  char		*types[10];
  char		*dup;
  int		i;

  init_tab(types);
  i = 0;
  while (types[i])
    {
      if (!strncmp(*str, types[i], strlen(types[i]))
	  && !isalnum((*str)[strlen(types[i])]))
	{
	  if (!(dup = strdup(types[i]))
	      || (add_end(&list, dup, TYPE)))
	    return (-1);
	  *str += strlen(types[i]);
	  return (0);
	}
      i += 1;
    }
  return (1);
}

static char	get_next_nonblank_char(char **str)
{
  char		*save;

  save = *str;
  while (*save == ' ')
    save++;
  return (*save);
}

int		parse_type(char **str, t_list *list)
{
  char		*save;
  char		*dup;

  if ((first_case(str, list) == 0))
    return (0);
  save = *str;
  if (isdigit((*str)[0]))
    return (-1);
  while (isalnum(**str) || **str == '_')
    (*str)++;
  if (*str == save
      || get_next_nonblank_char(str) == '\0'
      || **str != ' ')
    {
      *str = save;
      return (1);
    }
  if (!(dup = strndup(save, *str - save))
      || (add_end(&list, dup, TYPE)))
    return (-1);
  return (0);
}
