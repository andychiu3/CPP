# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achiu <achiu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 15:59:33 by achiu             #+#    #+#              #
#    Updated: 2024/11/11 16:21:46 by achiu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Zombie

SRC			= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJ			= $(SRC:.cpp=.o)

C			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

all:		$(NAME)

$(NAME):	$(OBJ)
			$(C) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
			rm -rf $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
