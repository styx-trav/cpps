CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
NAME=ZombieHorde
SRC=main.cpp Zombie.cpp ZombieHorde.cpp

all: $(NAME)

$(NAME): $(SRC) Zombie.hpp
	$(CC) $(FLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all re fclean clean
