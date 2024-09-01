##
# ft_printf
#
# @file
# @version 0.1

# compiling library
CC := cc
CFLAGS := -Wall -Werror -Wextra

# compiling tests
CXX := g++
CXX_FLAGS := -Wall -Werror -Wextra
FSANITIZE = -fsanitize=address
LDFLAGS := -lgtest -lgtest_main -pthread #for googletests

# including header files
INCLUDES = -Iincludes

BIN_DIR := ./bin
SRC_DIR := ./src
OBJ_DIR := ./dir

LIBFT := libft
NAME := libftprintf.a
TEST_TARGET := bin/run_tests

############ Rules ##################
#Mandatory targets
all:  $(NAME)

$(NAME): ft_printf.o $(LIBFT)/libft.a
	ar rc $@ $^

ft_printf.o: src/ft_printf.c
	$(CC) $(CFLAGS) $(INCLUDES) -Ilibft -c $< -o $@

$(LIBFT)/libft.a:
	$(MAKE) -C libft

$(TEST_TARGET): $(NAME)
	@mkdir -p ./bin
	$(CXX) $(CXX_FLAGS) $(INCLUDES) $(FSANITIZE) -o $@ tests/main.cpp $(LDFLAGS) $(NAME) $(LIBFT)/libft.a

############ PHONY ##################
clean:
	rm -f ft_printf.o

fclean: clean
	rm -f $(BIN_DIR)/*
	rm -f $(NAME)

bear: $(TEST_TARGET) ft_printf.o

test: $(TEST_TARGET)
	- $(TEST_TARGET)

############ PRINTING ##################
#Phony targets
.PHONY: all clean fclean test
# end
