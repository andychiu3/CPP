# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achiu <achiu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 18:08:02 by achiu             #+#    #+#              #
#    Updated: 2024/11/12 11:56:26 by achiu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= violence

SRC			= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJ			= $(SRC:.cpp=.o)

C 			= c++
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
