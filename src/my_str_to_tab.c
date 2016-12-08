/*
** my_str_to_tab.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell1
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sat Jan 23 19:43:42 2016 Jean PLANCHER
** Last update Sat May 14 09:03:23 2016 Jean PLANCHER
*/

#include "rush.h"

static int     tabcnw(const char *str, char sep1, char sep2)
{
  int   i;
  int   n;

  i = 0;
  n = 1;
  while (str[i] != '\0' && str[i] != '\n')
    {
      if ((str[i] == sep1 || str[i] == sep2) && str[i + 1] != '\0')
        ++n;
      ++i;
    }
  return (n);
}

static int     tabcn(const char *str, char sep1, char sep2)
{
  int   c;

  c = 0;
  while ((str[c] != sep1) && (str[c] != '\0') &&
	 (str[c] != sep2) && (str[c] != '\n'))
    ++c;
  c += 1;
  return (c);
}

char    **my_str_to_tab(const char *str, char sep1, char sep2)
{
  char  **tab;
  int   iba[3];
  int	temp;

  iba[0] = iba[1] = iba[2] = 0;
  temp = sizeof(char *) * ((tabcnw(str, sep1, sep2) + 1));
  if ((tab = malloc(temp)) == NULL)
    return (NULL);
  memset(tab, 0, temp);
  while (str[iba[0]] != '\n' && str[iba[0]] != '\0')
    {
      if (str[iba[0]] == sep1 || str[iba[0]] == sep2 || str[iba[0]] == '\n')
        {
          while ((str[iba[0]] == sep1 || str[iba[0]] == sep2) && (++iba[0]));
          ++iba[2];
	  iba[1] = 0;
        }
      temp = sizeof(char) * (tabcn(str + iba[0], sep1, sep2) + 1);
      if ((tab[iba[2]] = malloc(temp)) == NULL)
	return (NULL);
      memset(tab[iba[2]], 0, temp);
      while (str[iba[0]] != sep1 && str[iba[0]] != sep2 && str[iba[0]] != '\n'
	     && str[iba[0]] != '\0' && (tab[iba[2]][iba[1]++] = str[iba[0]++]));
    }
  return (tab);
}
