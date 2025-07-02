NAME = FragTrap

CC = c++
INC = inc/
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCF = srcs/
OBJF = objs/
FILE = main ClapTrap ScavTrap FragTrap
SRCS = $(addprefix $(SRCF), $(addsuffix .cpp, $(FILE)))
OBJS = $(patsubst $(SRCF)%.cpp, $(OBJF)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJF)%.o:$(SRCF)%.cpp
	@mkdir -p $(OBJF)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC)

clean:
	rm -rf $(OBJF)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
