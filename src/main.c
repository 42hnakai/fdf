/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:44:47 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/05 19:02:28 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	if ((x < 100 || 1900 < x) || (y < 100 || 1000 < y))
		return;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void draw_fdf(char *file_name, t_data img)
{
	int x;
	int y;
	t_map_info **map_info;
	t_map_size map_size;

	x = 0;
	y = 0;
	map_size = get_map_size(file_name);
	map_info = malloc_map_info(map_size);
	if (map_info == NULL)
	{
		printf("[ERROR!] fail malloc");
		exit(1);
	}
	map_info = get_map_info(map_info, map_size, file_name);
	map_info = get_map_vector(map_info, map_size);
	while (y < map_size.y_length)
	{
		x = 0;
		while (x < map_size.x_length)
		{
			if (x + 1 < map_size.x_length)
				drawline(map_info[y][x], map_info[y][x + 1], img);
			if (y + 1 < map_size.y_length)
				drawline(map_info[y][x], map_info[y + 1][x], img);
			x++;
		}
		y++;
	}
}

int main(int argc, char *argv[])
{
	void *mlx;
	void *mlx_win;
	t_data img;

	if (argc != 2)
		return (display_error("[ERROR!] no file"));
	if (check_valid_file(argv[1]) == -1)
		return (display_error("[ERROR!] invalid file"));
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
								 &img.line_length, &img.endian);
	if (check_valid_map(argv[1]) == -1)
		return (-1);
	draw_fdf(argv[1], img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
