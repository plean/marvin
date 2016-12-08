/*
** token_prefix.c for  in /home/melis_m/code/rendu/marvin_planch_j/src/
**
** Made by Matteo Melis
** Login   <melis_m@epitech.eu>
**
** Started on  Sun May 15 07:01:52 2016 Matteo Melis
** Last update Sun May 15 22:57:34 2016 Matteo Melis
*/

#include "rush.h"

static void	init_tab(char *prefixes[6])
{
  prefixes[0] = "extern";
  prefixes[1] = "auto";
  prefixes[2] = "static";
  prefixes[3] = "register";
  prefixes[4] = "global";
  prefixes[5] = NULL;
}

int		parse_prefix(char **str, t_list *list)
{
  char		*prefixes[6];
  char		*dup;
  int		i;

  i = 0;
  init_tab(prefixes);
  while (prefixes[i])
    {
      if (!strncmp(prefixes[i], *str, strlen(prefixes[i]))
	  && !isalnum((*str)[strlen(prefixes[i])]))
	{
	  if (!(dup = strdup(prefixes[i]))
	      || (add_end(&list, dup, PREFIX)))
	    {
	      fprintf(stderr, "%s\n", MAL);
	      return (-1);
	    }
	  *str += strlen(prefixes[i]);
	  return (0);
	}
      i += 1;
    }
  return (1);
}
