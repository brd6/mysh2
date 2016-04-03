##
## Makefile for mysh in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2
## 
## Made by Berdrigue BONGOLO BETO
## Login   <bongol_b@epitech.net>
## 
## Started on  Tue Mar 15 13:13:34 2016 Berdrigue BONGOLO BETO
## Last update Sun Apr  3 02:27:54 2016 Berdrigue BONGOLO BETO
##

CC	= 	gcc -g3 # <=

RM	= 	rm -f

NAME	= 	mysh

SRCS	= 	src/main.c \
		src/free_mysh.c \
		src/signal_handler.c \
		src/init_builtins.c \
		src/utils.c \
		src/parsing/check_valid_line.c \
		src/parsing/parser_checker.c \
		src/parsing/parser_errors.c \
		src/parsing/parser_checker2.c \
		src/parsing/parser_utils.c \
		src/list_utils.c \
		src/env_util.c \
		src/env_util2.c \
		src/prompt.c \
		src/exec_multi_cmd.c \
		src/builtins/builtin_exit.c \
		src/exec_multi_pipes.c \
		src/exec_simple_cmd.c \
		src/generate_commands_list.c \

OBJS	= 	$(SRCS:.c=.o)

#CFLAGS	+=	-W -Wall -Werror -pedantic
CFLAGS	+=	-I./include/ -I./lib/my/include/ -I./lib/my_printf/include/

LDFLAGS +=	-L./lib -lmy -L./lib/my_printf -lmyprintf
#LDFLAGS +=	-lncurses

all: libmy libmyprintf $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

libmy:
	$(MAKE) -C lib/my

libmyprintf:
	$(MAKE) -C lib/my_printf

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C lib/my
	$(MAKE) clean -C lib/my_printf

fclean: clean
	$(MAKE) fclean -C lib/my
	$(MAKE) fclean -C lib/my_printf
	$(RM) $(NAME)

re: fclean all

.PHONY: clean, mrproper, re, all, fclean
