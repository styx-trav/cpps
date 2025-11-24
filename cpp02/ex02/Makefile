CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
NAME=fixer
SRC=main.cpp Fixed.cpp

all: $(NAME)

$(NAME): $(SRC) Fixed.hpp
	$(CC) $(FLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all re fclean clean
