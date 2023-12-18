NAME = PmergeMe

SRCS =	main.cpp		\

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
	rm -rf output.txt
	./$(NAME) `jot -r 10 0 100 | tr '\n' ' '` >> output.txt
	./$(NAME) `jot -r 15 0 100 | tr '\n' ' '` >> output.txt
	./$(NAME) `jot -r 50 0 500 | tr '\n' ' '` >> output.txt
	./$(NAME) `jot -r 55 0 500 | tr '\n' ' '` >> output.txt
	./$(NAME) `jot -r 100 0 1000 | tr '\n' ' '` >> output.txt
	./$(NAME) `jot -r 111 0 1000 | tr '\n' ' '` >> output.txt
	./$(NAME) `jot -r 1000 0 10000 | tr '\n' ' '` >> output.txt
	./$(NAME) `jot -r 1111 0 10000 | tr '\n' ' '` >> output.txt
	./$(NAME) `jot -r 3500 0 100000 | tr '\n' ' '` >> output.txt
	./$(NAME) `jot -r 3555 0 100000 | tr '\n' ' '` >> output.txt

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