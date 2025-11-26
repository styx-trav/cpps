CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
NAME=open
SRC=main.cpp ClapTrap.cpp

all: $(NAME)

$(NAME): $(SRC) ClapTrap.hpp
	$(CC) $(FLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all re fclean clean
