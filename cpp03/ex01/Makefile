CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
NAME=serena
SRC=main.cpp ClapTrap.cpp ScavTrap.cpp

all: $(NAME)

$(NAME): $(SRC) ClapTrap.hpp ScavTrap.hpp
	$(CC) $(FLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all re fclean clean
