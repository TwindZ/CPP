NAME = ex01

SRCS =	main.cpp		\
		zombieHorde.cpp \
		Zombie.cpp		\

HEADERS =	-I Zombie.hpp	\

OBJS_DIR = ./objs/
OBJS = $(SRCS:%.cpp=$(OBJS_DIR)%.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

GREEN = \033[1;32m
RED = \033[1;31m
NC = \033[0;0m

all: $(NAME)

$(OBJS_DIR)%.o:%.cpp
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(HEADERS) -o $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

bonus: re

re: fclean all

.PHONY: all clean fclean bonus re