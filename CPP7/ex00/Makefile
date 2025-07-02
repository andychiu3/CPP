NAME = startWithAFewFunctions

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
INC = -Iinc

FILE = main
SRC	= $(addprefix src/, $(addsuffix .cpp, $(FILE)))
OBJ = $(patsubst src/%, obj/%, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(INC) $(OBJ) -o $(NAME)

obj/%.o: src/%.cpp
	mkdir -p obj/
	$(CXX) $(CXXFLAGS) $(INC) -c $^ -o $@

clean:
	rm -rf obj/

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
