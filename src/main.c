/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:44:47 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/13 02:31:23 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((x < 0 || 1919 < x) || (y < 0 || 1079 < y))
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_fdf(char *file_name, t_vars *vars)
{
	int			x;
	int			y;
	t_map_size	map_size;

	x = 0;
	y = 0;
	map_size = get_map_size(file_name);
	vars->map_info = malloc_map_info(map_size);
	vars->map_info = get_map_info(vars->map_info, map_size, file_name);
	vars->map_info = get_map_vector(vars->map_info, map_size);
	while (y < map_size.y_length)
	{
		x = 0;
		while (x < map_size.x_length)
		{
			if (x + 1 < map_size.x_length)
				drawline(vars->map_info[y][x], vars->map_info[y][x + 1],
					map_size, vars->img);
			if (y + 1 < map_size.y_length)
				drawline(vars->map_info[y][x], vars->map_info[y + 1][x],
					map_size, vars->img);
			x++;
		}
		y++;
	}
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (check_file(argc, argv[1]) == -1)
		return (-1);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	vars.img.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	if (check_valid_map(argv[1]) == -1)
		exit(1);
	draw_fdf(argv[1], &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_hook(vars.win, 2, 0, esc_close, &vars);
	mlx_hook(vars.win, 17, 0, x_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q fdf");
// }