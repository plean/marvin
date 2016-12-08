/*
** lexer.c for  in /home/planch_j/rendu/CPE/marvin_planch_j/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sat May 14 09:07:25 2016 Jean PLANCHER
** Last update Sun May 15 18:13:30 2016 Matteo Melis
*/

#include "rush.h"

static int	check_parenthesis(char *str)
{
  int		count;
  char		*save;

  count = 0;
  save = str;
  while (*str)
    {
      count += (*str == '(') - (*str == ')');
      if (count < 0)
	{
	  fprintf(stderr, "%s\n", UNX_PARENTHESIS);
	  error_line(save, str - save);
	  return (1);
	}
      str++;
    }
  if (count == 0)
    return (0);
  fprintf(stderr, "%s\n", UNTRM_PARENTHESIS);
  return (1);
}

static void	init_func_ptr(int (*parse_func[8])(char **str, t_list *list))
{
  parse_func[0] = &parse_const_volatile;
  parse_func[1] = &parse_prefix;
  parse_func[2] = &parse_comma;
  parse_func[3] = &parse_type;
  parse_func[4] = &parse_name;
  parse_func[5] = &parse_parenthesis;
  parse_func[6] = &parse_pointer;
  parse_func[7] = NULL;
}

static int	iter_token(char **str, t_list **list,
		    int *i, int (*parse_func[8])(char **str, t_list *list))
{
  int		ret;

  while (**str == ' ')
    (*str)++;
  if ((ret = parse_func[*i](str, *list)) == 0)
    *i = -1;
  else if (ret == -1)
    return (-1);
  return (0);
}

static int	check_bad_token(int i, char *str, char *save, t_list **list)
{
  if (i == 7)
    {
      del_list(list);
      error_line(save, str - save);
      fprintf(stderr, "%s\n", UNKWN_TOKEN);
      return (-1);
    }
  return (0);
}

int		lexer(t_list **list, char *str)
{
  int		i;
  char		*save;
  int		(*parse_func[8])(char **str, t_list *list);

  save = str;
  if (check_parenthesis(str) != 0)
    return (-1);
  *list = create_list();
  init_func_ptr(parse_func);
  i = 0;
  while (*str)
    {
      if ((iter_token(&str, list, &i, parse_func)) == -1)
	{
	  del_list(list);
	  return (-1);
	}
      if (check_bad_token(++i, str, save, list) == -1)
	return (-1);
    }
  return (0);
}
