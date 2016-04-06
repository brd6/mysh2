##
## Makefile for mysh in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2
## 
## Made by Berdrigue BONGOLO BETO
## Login   <bongol_b@epitech.net>
## 
## Started on  Tue Mar 15 13:13:34 2016 Berdrigue BONGOLO BETO
## Last update Thu Apr  7 00:25:54 2016 Berdrigue BONGOLO BETO
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
		src/builtins/builtin_cd.c \
		src/builtins/builtin_env.c \
		src/builtins/builtin_setenv.c \
		src/builtins/builtin_unsetenv.c \
		src/exec_multi_pipes.c \
		src/exec_simple_cmd.c \
		src/parsing/generate_commands_list.c \
		src/my_heredoc.c \
		src/exec_utils.c \
		src/fork_action.c \
		src/get_bin_path.c \
		src/redirect_cmd.c \
		src/epur_str.c \

OBJS	= 	$(SRCS:.c=.o)

#CFLAGS	+=	-W -Wall -Werror -pedantic
CFLAGS	+=	-I./include/ -I./lib/my/include/ -I./lib/my_printf/include/

LDFLAGS +=	-L./lib -lmy -L./lib/my_printf -lmyprintf

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
