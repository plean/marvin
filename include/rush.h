/*
** rush.h for  in /home/planch_j/rendu/CPE/marvin_planch_j/include/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri May 13 21:44:58 2016 Jean PLANCHER
** Last update Sun May 15 23:23:09 2016 Matteo Melis
*/

#ifndef RUSH_H_
# define RUSH_H_

# include <ctype.h>
# include <strings.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include "list.h"
# include "lang.h"

# define ATC_TAB __attribute__ ((cleanup(free_tab)))
# define CONST "const"
# define CHAR "char"
# define INT "int"
# define FLOAT "float"
# define SHORT "short"
# define SIGNED "signed"
# define UNSIGNED "unsigned"
# define STATIC "static"
# define REGISTER "register"
# define EXTERN "extern"
# define VOID "void"

typedef enum	e_token
{
  TYPE,
  NAME,
  POINTER,
  PREFIX,
  COMMA,
  CONST_VOLATILE,
  PARENTHESIS,
  ELSE
}		t_token;

char		*strdup(const char *s);
char		*strndup(const char *s, size_t n);
int		error(int ac, char *str);
void		error_line(char *str, int nb);
char		*cut_space(char *buffer);
char		*cut_pv(char *buffer);
char		**my_str_to_tab(const char *str, char sep1, char sep2);
void		free_tab(char ***to_free);
void		marvin(t_list *list);
int		lexer(t_list **list, char *str);
int		check_errors(t_list *list);
int		show_error(t_list *list, t_element *elem);
int		aff_vf(t_element *elem);
void		aff_func(t_element *elem);
void		aff_var(t_element *elem);
void		aff_pfunc(t_element *elem);
int		errors_expression(t_list *list);
t_element	*getntoken(t_list *list, int n, t_token token);
int		parse_const_volatile(char **str, t_list *list);
int		parse_comma(char **str, t_list *list);
int		parse_type(char **str, t_list *list);
int		parse_name(char **str, t_list *list);
int		parse_pointer(char **str, t_list *list);
int		parse_parenthesis(char **str, t_list *list);
int		parse_prefix(char **str, t_list *list);
int		find_comma(t_element *elem);
int		aff_token(char *str);

#endif /* !RUSH_H_ */
