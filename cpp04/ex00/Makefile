CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
NAME=poly
SRC=main.cpp Animal.cpp WrongAnimal.cpp Cat.cpp Dog.cpp WrongCat.cpp

all: $(NAME)

$(NAME): $(SRC) Animal.hpp WrongAnimal.hpp Cat.hpp Dog.hpp WrongCat.hpp
	$(CC) $(FLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all re fclean clean
