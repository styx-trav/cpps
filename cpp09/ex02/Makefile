CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
NAME=PmergeMe
SRC=main.cpp Pmerge_deq.cpp Pmerge_deq_utils.cpp PmergeMe.cpp Pmerge_vec.cpp Pmerge_vec_utils.cpp utils.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all re fclean clean
