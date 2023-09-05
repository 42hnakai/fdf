CC = cc
GFLAGS = -Wall -Wextra -Werror
NAME = fdf
SRC = src/drowline.c src/get_map_info.c src/get_map_vector.c src/color.c src/check_error.c\
	  src/utils.c src/main.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C get_next_line
	$(CC) $(GFLAGS) $(OBJ) -g -fsanitize=address -Llibft -lft -Lget_next_line -lget_next_line -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

.c.o:
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	make clean -C libft
	make clean -C get_next_line
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft
	make fclean -C get_next_line
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus