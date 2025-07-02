NAME = Identifier

CXX	= c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
INC = -Iinc/

FILES = main Base
SRCS = $(addprefix srcs/, $(addsuffix .cpp, $(FILES)))
OBJS = $(patsubst srcs/%.cpp, objs/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

objs/%.o:srcs/%.cpp
	@mkdir -p objs/
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

clean:
	rm -rf objs/

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
