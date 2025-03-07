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

BIN_DIR := bin
SRC_DIR := src
OBJ_DIR := obj
BUILD_DIR := build
TEST_DIR := tests
LIBFT_DIR := libft

SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp )
TEST_OBJ_FILES := $(TEST_FILES:$(TEST_DIR)/%.cpp=$(OBJ_DIR)/%.o)

NAME := libftprintf.a

############ Rules ##################
#Mandatory targets
all:  $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT_DIR)/libft.a
	cp $(LIBFT_DIR)/libft.a $(NAME)
	ar rc $(NAME) $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -I$(LIBFT_DIR) -c $< -o $@

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C libft

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

# Bonus target
BONUS_NAME := bonus_name
BONUS_INCLUDES := -Iincludes_bonus
BONUS_SRC_DIR := ./bonus
BONUS_SRC_FILES := $(wildcard $(BONUS_SRC_DIR)/*.c)
BONUS_OBJ_FILES := $(BONUS_SRC_FILES:$(BONUS_SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_TEST_DIR := ./tests_bonus
BONUS_TEST_FILES := $(wildcard $(BONUS_TEST_DIR)/*.cpp )
BONUS_TEST_TARGET := bin/run_bonus_tests

$(BONUS_NAME): $(BONUS_OBJ_FILES) $(LIBFT_DIR)/libft.a
	cp $(LIBFT_DIR)/libft.a libftprintf.a
	ar rc libftprintf.a $(BONUS_OBJ_FILES)

$(OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(BONUS_INCLUDES) -I$(LIBFT_DIR) -c $< -o $@

############ PHONY ##################
clean:
	$(MAKE) -C libft $@
	rm -f $(OBJ_FILES) $(BONUS_OBJ_FILES)

fclean: clean
	$(MAKE) -C libft $@
	rm -f $(BIN_DIR)/*
	rm -rf $(BIN_DIR)
	rm -rf $(OBJ_DIR)
	rm -rf $(BUILD_DIR)
	rm -f $(NAME)

re: fclean all

test: all
	- cmake -S . -B build
	- cmake --build build
	- ./build/run_tests
	- ./build/run_tests_bonus

examples: $(NAME)
	$(CC) -g $(INCLUDES) -I$(LIBFT_DIR) $(TEST_DIR)/examples.c -o $(TEST_DIR)/examples.out $(NAME)
	- @$(TEST_DIR)/examples.out

libft:
	$(MAKE) -C libft

norminette:
	norminette -R CheckForbiddenSourceHeader -R CheckDefine

bonus: $(BONUS_NAME)

examples-bonus: $(BONUS_NAME)
	$(CC) -g $(BONUS_INCLUDES) -I$(LIBFT_DIR) $(BONUS_TEST_DIR)/examples_bonus.c -o $(BONUS_TEST_DIR)/examples_bonus.out $(NAME)
	- @$(BONUS_TEST_DIR)/examples_bonus.out

############ PRINTING ##################
#Phony targets
.PHONY: all clean fclean test libft bonus test-bonus

print_test_files:
	@echo $(TEST_FILES)

print_test_obj_files:
	@echo $(TEST_OBJ_FILES)
# end
