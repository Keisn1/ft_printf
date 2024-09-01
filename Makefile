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
OBJ_DIR := ./obj

SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT := libft
NAME := libftprintf.a
TEST_TARGET := bin/run_tests

############ Rules ##################
#Mandatory targets
all:  $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT)/libft.a $(BIN_DIR)
	cp $(LIBFT)/libft.a $(NAME)
	ar rc $(NAME) $<

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -I$(LIBFT) -c $< -o $@

$(LIBFT)/libft.a:
	$(MAKE) -C libft

$(TEST_TARGET): $(NAME) $(BIN_DIR)
	$(CXX) $(CXX_FLAGS) $(INCLUDES) $(FSANITIZE) -o $@ tests/main.cpp $(LDFLAGS) $(NAME) $(LIBFT)/libft.a

############ PHONY ##################
clean:
	rm -f $(OBJ_FILES)
	rm -f $(OBJ_DIR)

fclean: clean
	rm -f $(BIN_DIR)/*
	rm -f $(BIN_DIR)
	rm -f $(NAME)

bear: $(TEST_TARGET) ft_printf.o

test: $(TEST_TARGET)
	- $(TEST_TARGET)

############ PRINTING ##################
#Phony targets
.PHONY: all clean fclean test
# end
