NAME = Bureaucrat

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
INC = -Iinc

FILE = main Bureaucrat
SRC = $(addprefix src/, $(addsuffix .cpp, $(FILE)))
OBJ = $(patsubst %.cpp, obj/%.o, $(notdir $(SRC)))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(INC) -o $(NAME)

obj/%.o: src/%.cpp
	mkdir -p obj/
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

clean:
	rm -rf obj/

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re