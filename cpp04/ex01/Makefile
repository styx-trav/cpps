CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
NAME=poly
SRC=main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp

all: $(NAME)

$(NAME): $(SRC) Animal.hpp Cat.hpp Dog.hpp Brain.hpp
	$(CC) $(FLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all re fclean clean
