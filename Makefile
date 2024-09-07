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

$(TEST_TARGET): $(NAME) | $(BIN_DIR)
	$(CXX) $(CXX_FLAGS) $(INCLUDES) $(FSANITIZE) -o $@ tests/main.cpp $(LDFLAGS) $(NAME) $(LIBFT)/libft.a

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

$(BONUS_NAME): $(BONUS_OBJ_FILES) $(LIBFT_DIR)/libft.a
	cp $(LIBFT_DIR)/libft.a libftprintf.a
	ar rc libftprintf.a $(BONUS_OBJ_FILES)

$(OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(BONUS_INCLUDES) -I$(LIBFT_DIR) -c $< -o $@

############ PHONY ##################
clean:
	rm -f $(OBJ_FILES) $(BONUS_OBJ_FILES)

fclean: clean
	rm -f $(BIN_DIR)/*
	rm -f $(NAME)

re: fclean all

bear: $(TEST_TARGET) $(OBJ_FILES)

test: $(TEST_TARGET)
	- $(TEST_TARGET)

libft:
	$(MAKE) -C libft

norminette:
	norminette -R CheckForbiddenSourceHeader -R CheckDefine

bonus: $(BONUS_NAME)
# bonus: SRC_DIR := ./bonus
# bonus: INCLUDES := -Iincludes_bonus
# bonus: SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
# bonus: OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
# bonus: all
# bonus: SRC_DIR := ./bonus
# bonus: SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
# bonus: OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
# bonus: INCLUDES := -Iincludes_bonus

# bonus:
# 	$(MAKE) all SRC_DIR="$(SRC_DIR)" SRC_FILES="$(SRC_FILES)" INCLUDES="$(INCLUDES)" OBJ_FILES="$(OBJ_FILES)"

############ PRINTING ##################
#Phony targets
.PHONY: all clean fclean test libft bonus

print_test_files:
	@echo $(TEST_FILES)

print_test_obj_files:
	@echo $(TEST_OBJ_FILES)
# end
