CC = g++
CFLAGS = -g -Wall -Wextra -Werror -std=c++98

NAME = swap
TEST_NAME = test_swap

SRCS = main.cpp Swap.cpp
TEST_SRCS = test_main.cpp Swap.cpp

OBJ_DIR = obj

OBJS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRCS))
TEST_OBJS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(TEST_SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

test: $(TEST_NAME)

$(TEST_NAME): $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $(TEST_NAME) $(TEST_OBJS)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

re: fclean all

.PHONY: all clean fclean re test