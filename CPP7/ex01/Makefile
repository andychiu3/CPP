NAME = iter

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
INC = -Iinc

FILE = main
SRC = $(addprefix src/, $(addsuffix .cpp, $(FILE)))
OBJ = $(patsubst src/%, obj/%, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(INC) $(OBJ) -o $(NAME)

obj/%.o: src/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INC) -c $^ -o $@

clean:
	rm -rf obj/

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
