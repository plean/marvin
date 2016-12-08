##
## Makefile for  in /home/planch_j/rendu/CPE/marvin_planch_j/src/
##
## Made by Jean PLANCHER
## Login   <planch_j@epitech.net>
##
## Started on  Fri May 13 21:24:47 2016 Jean PLANCHER
## Last update Sun May 15 21:59:48 2016 Jean PLANCHER
##

CC	= gcc

RM     	= rm -f

CFLAGS 	+= -W -Wall -ansi -pedantic -g3
CFLAGS  += -Iinclude/

FR	+= -Ilang/fr/

EN	+= -Ilang/en/

NAME1  	= marvin

SRCS   	= main.c \
	  cut_space.c \
	  error.c \
	  errors_marvin.c \
	  errors_expression.c \
	  free.c \
	  list.c \
	  aff_mess.c \
	  marvin.c \
	  misc.c \
	  lexer.c \
	  my_str_to_tab.c \
	  token_comma.c \
	  token_const_volatile.c \
	  token_name.c \
	  token_parenthesis.c \
	  token_pointer.c \
	  token_prefix.c \
	  token_type.c

SRCS :=	$(addprefix src/,$(SRCS))

OBJS1   = $(SRCS:.c=.o)
OBJS2	= $(SRCS:.c=.bite)

all: $(NAME1)

fr: $(NAME1)

en: bite

%.o: %.c
	@$(CC) -c $< -o $@ $(CFLAGS) $(FR) && \
	echo -e "\e[32m[OK]" $< "\e[93m"|| \
	echo -e "\e[91;5m[ERR]\e[25m" $< "\e[93m"

$(NAME1): $(OBJS1)
	@echo -e "\e[0m"
	@$(CC) $(OBJS1) -o $(NAME1)
	@$(RM) $(OBJS2)
	@echo -e "\e[32mAll done ! ==>\e[33m" $(NAME1) "\e[32mcreated !\e[0m"

%.bite:	%.c
	@$(CC) -c $< -o $@ $(CFLAGS) $(EN) && \
	echo -e "\e[32m[OK]" $< "\e[93m"|| \
	echo -e "\e[91;5m[ERR]\e[25m" $< "\e[93m"

bite: $(OBJS2)
	@echo -e "\e[0m"
	@$(CC) $(OBJS2) -o $(NAME1)
	@$(RM) $(OBJS1)
	@echo -e "\e[32mAll done ! ==>\e[33m" $(NAME1) "\e[32mcreated !\e[0m"

clean:
	@echo -en "\e[0mCleaning .o files..."
	@$(RM) $(OBJS1) $(OBJS2)
	@echo -e "       [\e[32mOk !\e[39m]\e[0m"

fclean: clean
	@echo -en "\e[39mCleaning executable..."
	@$(RM) $(NAME1) $(NAME2)
	@echo -e "		[\e[32m0k !\e[39m]\e[0m"

re: fclean all

.PHONY: all fr en clean fclean re
