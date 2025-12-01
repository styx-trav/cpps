CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
NAME=fullsend
SRC=AMateria.cpp \
Bite.cpp \
Boost.cpp \
Character.cpp \
Cure.cpp \
Ice.cpp \
main.cpp \
MateriaSource.cpp \
Monster.cpp \
Shield.cpp \

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all re fclean clean
