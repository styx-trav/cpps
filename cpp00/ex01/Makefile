CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
NAME=phoneBook
SRC=main.cpp

all: $(NAME)

$(NAME): $(SRC) Contact.hpp PhoneBook.hpp
	$(CC) $(FLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all re fclean clean
