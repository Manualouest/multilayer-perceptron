NAME = mlp

CXX = c++
CXXFLAGS = -g --std=c++17 -Wall -Wextra -Werror

INC = -Iinclude

SRC_DIR = src/
SRC =	main.cpp\
		brain/layer.cpp\
		brain/brain.cpp

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
DEP = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.d))

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(INC) $< -c -o $@
	@echo compiled $@

$(NAME): $(OBJ)
	@$(CXX)  $(CXXFLAGS) $(INC) $(OBJ) -o $(NAME)
	@echo $(NAME) made

clean:
	@rm -rf $(OBJ) $(DEP)

fclean: clean
	@rm -rf $(OBJ_DIR)

re: fclean all

.phony: all $(NAME) clean fclean re

-include $(DEP)