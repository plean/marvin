/*
** list.c for  in /home/planch_j/rendu/CPE/CPE_2015_corewar/corewar/parsing/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Mar 27 06:14:14 2016 Jean PLANCHER
** Last update Sun May 15 18:32:38 2016 Matteo Melis
*/

#include "rush.h"

t_list		*create_list(void)
{
  t_list	*list;
  if ((list = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  list->first = NULL;
  list->length = 0;
  return (list);
}

int		add_start(t_list **list, char *data, int token)
{
  t_element	*tmp;

  if ((tmp = malloc(sizeof(t_element))) == NULL)
    return (1);
  tmp->data = data;
  tmp->token = token;
  tmp->next = (*list)->first;
  (*list)->first = tmp;
  (*list)->length++;
  return (0);
}

int		add_end(t_list **list, char *data, int token)
{
  t_element	*tmp;
  t_element	*temp;

  if ((tmp = malloc(sizeof(t_element))) == NULL)
    return (1);
  tmp->data = data;
  tmp->token = token;
  temp = (*list)->first;
  if (!temp)
    (*list)->first = tmp;
  else
    {
      while (temp->next)
	temp = temp->next;
      temp->next = tmp;
    }
  tmp->next = NULL;
  (*list)->length++;
  return (0);
}

void		del_list(t_list **list)
{
  t_element	*tmp;

  while ((*list)->first != NULL)
    {
      tmp = (*list)->first->next;
      free((*list)->first->data);
      free((*list)->first);
      (*list)->first = tmp;
      (*list)->length--;
    }
  free((*list));
}
