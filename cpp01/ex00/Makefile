CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
NAME=Zombie
SRC=main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

all: $(NAME)

$(NAME): $(SRC) Zombie.hpp
	$(CC) $(FLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all re fclean clean
