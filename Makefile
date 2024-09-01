##
# ft_printf
#
# @file
# @version 0.1

CC := cc
CFLAGS := -Wall -Werror -Wextra

BIN_DIR := ./bin
SRC_DIR := ./src
OBJ_DIR := ./dir

LIBFT := libft

NAME := libftprintf.a

############ Rules ##################
#Mandatory targets
all:  $(NAME)

$(NAME): $(LIBFT)/libft.a ft_printf.o
	ar rc $@ $^

ft_printf.o: ft_printf.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT)/libft.a:
	$(MAKE) -C libft

clean:
	$(MAKE) -C $(LIBFT) clean
	rm -f ft_printf.o

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(NAME)

# end
