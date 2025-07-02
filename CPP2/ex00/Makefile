NAME		= fpNumber

SRC			= main.cpp Fixed.cpp
OBJ			= $(SRC:.cpp=.o)

CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
			rm -rf $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
