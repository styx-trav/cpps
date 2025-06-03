CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
NAME=Violence
SRC=main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

all: $(NAME)

$(NAME): $(SRC) HumanA.hpp HumanB.hpp Weapon.hpp
	$(CC) $(FLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all re fclean clean
