NAME = ircsrv

CXX = c++

CFLAGS =  -Wall -Wextra -Werror -std=c++98 -I inc

SRC_DIR = src
OBJ_DIR = obj

SRC = 	src/Channel.cpp\
		src/cmd_channel.cpp\
		src/cmd_message.cpp\
		src/cmd_oper.cpp\
		src/Dispatch.cpp\
		src/main.cpp\
		src/Replies.cpp\
		src/server.cpp\
		src/Utils.cpp

OBJ := $(SRC:src/%.cpp=$(OBJ_DIR)/%.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(@D)
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean 
	make all

.Phony: all clean fclean re