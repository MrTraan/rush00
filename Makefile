NAME = schmup

CPP_FILES = ./src/main.cpp

O_FILES = $(CPP_FILES:%.cpp=%.o)

CC = clang++
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(O_FILES)
	$(CC) $(FLAGS) $^ $(INCLUDES) -o $@

%.o: %.cpp
	$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all fclean re
