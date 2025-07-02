NAME = ClapTrap

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJF = objs/
FILE = main ClapTrap
SRCS = $(addsuffix .cpp, $(FILE))
OBJS = $(addprefix $(OBJF), $(addsuffix .o, $(FILE)))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJF)%.o: %.cpp
	@mkdir -p $(OBJF)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJF)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
