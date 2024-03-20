NAME			= megaphone
SRCS			= megaphone.cpp
OBJ_DIR			= obj
OBJS			= $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))
CC				= c++ 
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror -std=c++98
MK				= mkdir -p

all:			$(OBJ_DIR) $(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR):
	$(MK) $(OBJ_DIR)

$(OBJ_DIR)/%.o:	%.cpp Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:			
				$(RM) $(OBJ_DIR)

fclean:			clean
				$(RM) $(NAME)
				
re:				fclean all

.PHONY:			all clean fclean re bonus