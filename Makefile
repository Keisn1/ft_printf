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
all: $(LIBFT)/libft.a

$(LIBFT)/libft.a:
	$(MAKE) -C libft

clean:
	$(MAKE) -C $(LIBFT) clean

fclean:
	$(MAKE) -C $(LIBFT) fclean

# end
