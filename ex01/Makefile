NAME = Bureaucrat
CC = c++
CCFLAGS = -Wall -Wextra -Werror -std=c++98


SRC_DIR = ./
SRC = $(shell find $(SRC_DIR) -type f -name "*.cpp")
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re