/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:44:47 by hnakai            #+#    #+#             */
/*   Updated: 2023/08/27 18:08:08 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

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
	int i;
	int j;

	i = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// OPEN FILE "10-2.fdf"
	map_size = get_map_size();
	map_info = malloc_map_info(map_size);
	map_info = get_map_info(map_info);
	// put dot
	while (i < map_size.y_length)
	{
		j = 0;
		while (j < map_size.x_length)
		{
			my_mlx_pixel_put(&img, 10 + i * 10, 10 + j * 10, 0x00FF0000);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
