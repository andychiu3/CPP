NAME = deepCopy

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc/

FILE = Animal Dog Cat Brain
SRCS = main.cpp $(addprefix srcs/, $(addsuffix .cpp, $(FILE)))
OBJS = $(patsubst %.cpp, objs/%.o, $(notdir $(SRCS)))

vpath %.cpp srcs

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

objs/%.o: %.cpp
	@mkdir -p objs/
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf objs/

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
