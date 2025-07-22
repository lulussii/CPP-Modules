CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude -g
SRC_DIR = src
OBJ_DIR = build

SRCS = 	$(SRC_DIR)/main.cpp \
		$(SRC_DIR)/Harl.cpp
	
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

NAME = harl

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
