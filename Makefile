CC = cc
GFLAGS = -Wall -Wextra -Werror -O2
NAME = fdf
SRC = src/drawline.c src/drawline_utils.c src/get_map_info.c src/get_map_info_utils.c src/get_map_vector.c\
	  src/check_color_utils.c src/color.c src/check_error.c\
	  src/utils.c src/main.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C get_next_line
	make -C ft_printf
	$(CC) $(GFLAGS) $(OBJ) -g -fsanitize=address -Llibft -lft -Lget_next_line -lget_next_line -Lft_printf -lftprintf -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

.c.o:
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	make clean -C libft
	make clean -C get_next_line
	make clean -C ft_printf
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft
	make fclean -C get_next_line
	make fclean -C ft_printf
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus