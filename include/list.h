/*
** list.h for  in /home/planch_j/rendu/CPE/CPE_2015_corewar/corewar/parsing/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Mar 27 04:31:11 2016 Jean PLANCHER
** Last update Sun May 15 04:10:18 2016 Jean PLANCHER
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct		s_element
{
  int			token;
  char			*data;
  struct s_element	*next;
}			t_element;

typedef struct	s_list
{
  int		length;
  t_element	*first;
}		t_list;

/*
** List
*/

t_list		*create_list(void);
int		add_start(t_list **list, char *data, int token);
int		add_end(t_list **list, char *data, int token);
void		del_list(t_list **list);
void		aff_list(t_list *list);

#endif /* !LIST_H_ */
