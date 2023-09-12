CC = cc
GFLAGS = -Wall -Wextra -Werror
NAME = libget_next_line.a
SRC = get_next_line_utils.c get_next_line.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar r $(NAME) $(OBJ)

.c.o:
	$(CC) $(GFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re