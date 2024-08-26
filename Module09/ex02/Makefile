NAME	= PmergeMe

SRC 	= $(wildcard *.cpp)

OBJ		= $(patsubst %.cpp, %.o, $(SRC))

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 $(INCLUDES) #-g3 -fsanitize=address
HEADERS 	= $(wildcard *.hpp)
INCLUDES	= -I./

# test :
# 	@echo $(HEADERS)

all: $(NAME)

%.o: %.cpp $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)
	
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re