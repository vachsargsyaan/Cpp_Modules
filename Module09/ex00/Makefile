NAME = btc
COMPILER = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC = $(wildcard *.cpp)
LIBS = $(wildcard *.hpp)

OBJ = $(patsubst %.cpp, %.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ) Makefile $(LIBS)
	$(COMPILER) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\nExecutable is - $(NAME)"

%.o: %.cpp $(LIBS)
	$(COMPILER) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re