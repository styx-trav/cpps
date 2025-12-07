CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
NAME=28B
SRC=main.cpp ShrubberyCreationForm.cpp AForm.cpp Bureaucrat.cpp CustomException.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all re fclean clean
