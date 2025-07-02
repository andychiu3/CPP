NAME = Polymorphism

CC = c++
CFLAGS = -Wall -Wextra -Werror -Iinc/

FILE = Animal Dog Cat WrongAnimal WrongCat
SRCS = main.cpp $(addprefix srcs/, $(addsuffix .cpp, $(FILE)))
OBJS = $(patsubst srcs/%.cpp, objs/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

objs/%.o: srcs/%.cpp
	@mkdir -p objs/
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf objs/

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
