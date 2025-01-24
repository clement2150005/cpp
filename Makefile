NAME        =   megaphone
SRC_DIR     =   src
OBJ_DIR     =   obj
CXX         =   c++
CXXFLAGS    =   -Wall -Werror -Wextra -std=c++98
RM          =   rm -rf

SRCS        =   $(shell find $(SRC_DIR) -name '*.cpp')
OBJS        =   $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
