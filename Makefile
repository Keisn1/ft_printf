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
TESTS_DIR := ./tests
LIBFT_DIR := ./libft

SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

TEST_FILES := $(wildcard $(TESTS_DIR)/*.cpp )
TEST_OBJ_FILES := $(TEST_FILES:$(TESTS_DIR)/%.cpp=$(OBJ_DIR)/%.o)

NAME := libftprintf.a

TEST_TARGET := bin/run_tests

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

$(TEST_TARGET): $(TEST_FILES) $(NAME) | $(BIN_DIR)
	$(CXX) $(CXX_FLAGS) $(FSANITIZE) -o $@ $(TEST_FILES) $(LDFLAGS) $(NAME) $(INCLUDES)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

############ PHONY ##################
clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(BIN_DIR)/*
	rm -f $(NAME)

re: fclean all

bear: $(TEST_TARGET) $(OBJ_FILES)

test: $(TEST_TARGET)
	- $(TEST_TARGET)

examples: $(NAME)
	@$(CC) $(CFLAGS) $(INCLUDES) -I$(LIBFT_DIR) $(TESTS_DIR)/examples.c -o $(TESTS_DIR)/examples.out $(NAME)
	- @$(TESTS_DIR)/examples.out

libft:
	$(MAKE) -C libft

norminette:
	norminette -R CheckForbiddenSourceHeader -R CheckDefine

norminette-src:
	norminette -R CheckForbiddenSourceHeader -R CheckDefine $(SRC_DIR)
############ PRINTING ##################
#Phony targets
.PHONY: all clean fclean test libft

print_test_files:
	@echo $(TEST_FILES)

print_test_obj_files:
	@echo $(TEST_OBJ_FILES)
# end
