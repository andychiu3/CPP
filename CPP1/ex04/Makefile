# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 13:28:14 by achiu             #+#    #+#              #
#    Updated: 2024/11/13 20:21:50 by fiftyblue        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Sed

SRC			= main.cpp
OBJ			= $(SRC:.cpp=.o)

C			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -pedantic-errors -Weverything

all:		$(NAME)

$(NAME):	$(OBJ)
			$(C) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
			rm -rf $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
