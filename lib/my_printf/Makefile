##
## Makefile for my_printf in /home/bongol_b/rendu/my_printf
##
## Made by berdrigue bongolo-beto
## Login   <bongol_b@epitech.net>
##
## Started on  Sun Nov  1 21:13:19 2015 berdrigue bongolo-beto
## Last update Sun Jan 24 19:30:43 2016 Berdrigue BONGOLO BETO
##

CC	= 	gcc

RM	= 	rm -Rf

AR	= 	ar cr

NAME 	= 	libmyprintf.a

CFLAGS	=	-I./include

LIBCPY	=	cp -f $(NAME) ../

SRCS	=	my_strlen_x.c \
		my_nbr_len_x.c \
		my_printf.c \
		my_utils.c \
		my_strdup_x.c \
		my_putchar_x.c \
		print_char.c \
		my_put_nbr_x.c \
		init_arg.c \
		my_get_char_pos_x.c \
		print_nbr.c \
		my_strcpy_x.c \
		print_str.c \
		my_putstr_x.c \
		print_nil.c \
		my_atoi_x.c \
		print_utils.c \
		my_putnstr_x.c \
		print_percent.c \
		check_format.c \
		print_utils2.c \
		my_putnbr_base_x.c \
		print_octal.c \
		print_unsigned_nbr.c \
		print_hexa.c \
		print_pointer.c \
		print_ncount.c \
		my_itoa_x.c \
		print_binary.c \
		print_str2.c \
		convert_base_x.c \
		my_getnbr_base_x.c \
		my_revstr_x.c \
		my_putnbr_x.c

OBJS	= 	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	ranlib $(NAME)
	$(LIBCPY)

$(OBJS) :
	$(CC) -c $(SRCS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean, mrproper, re, all, fclean
