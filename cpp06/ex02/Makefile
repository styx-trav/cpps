CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
NAME=identify
SRC=main.cpp Base.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all re fclean clean
