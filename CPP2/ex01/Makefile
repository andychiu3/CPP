NAME		= fpn

SRC			= main.cpp Fixed.cpp
OBJ			= $(SRC:.cpp=.o)

CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -pedantic-errors -std=c++98

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
			rm -rf $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re