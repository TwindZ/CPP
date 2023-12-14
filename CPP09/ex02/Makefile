NAME = PmergeMe

SRCS =	main.cpp		\
		PmergeMe.cpp	\

OBJS_DIR = ./objs/
SRCS_DIR = ./srcs/
OBJS = $(SRCS:%.cpp=$(OBJS_DIR)%.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

GREEN = \033[1;32m
RED = \033[1;31m
NC = \033[0;0m

all: $(NAME)
$(OBJS_DIR)%.o:$(SRCS_DIR)%.cpp
	
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)

	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "${GREEN}$(NAME) COMPILED${NC}"

run: re

	@echo "${GREEN}$(NAME) RUN${NC}"
	./$(NAME) 21 20 19 18 17 16 15 14 13 12 11 10 9

leaks: re 
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)
	rm -rf ./$(NAME).dSYM

clean:

	@rm -rf $(OBJS_DIR)
	@echo "${RED}$(NAME) OBJECTS DELETED${NC}"

fclean: clean

	@rm -f $(NAME)
	@echo "${RED}$(NAME) EXECUTABLE DELETED${NC}"

bonus: re

re: fclean all

.PHONY: all clean fclean bonus re run