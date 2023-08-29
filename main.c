/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:44:47 by hnakai            #+#    #+#             */
/*   Updated: 2023/08/29 23:50:21 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	if ((x < 0 || 1920 < x) || (y < 0 || 1080 < y))
		printf("[!ERROR!] over map!\n");
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int main(void)
{
	void *mlx;
	void *mlx_win;
	t_data img;
	t_map_info **map_info;
	t_map_size map_size;
	int x;
	int y;

	x = 0;
	y = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// OPEN FILE "10-2.fdf"
	map_size = get_map_size();
	map_info = malloc_map_info(map_size);
	map_info = get_map_info(map_info, map_size);
	map_info = get_map_vector(map_info, map_size);
	// PLOT
	while (y < map_size.y_length)
	{
		x = 0;
		while (x + 1 < map_size.x_length)
		{
			drowline(500 + 30 * map_info[y][x].x, 500 + 30 * map_info[y][x + 1].x, 500 + 30 * map_info[y][x].y, 500 + 30 * map_info[y][x + 1].y, img);
			x++;
		}
		y++;
	}
	y = 0;
	while (y + 1 < map_size.y_length)
	{
		x = 0;
		while (x < map_size.x_length)
		{
			drowline(500 + 30 * map_info[y][x].x, 500 + 30 * map_info[y + 1][x].x, 500 + 30 * map_info[y][x].y, 500 + 30 * map_info[y + 1][x].y, img);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
