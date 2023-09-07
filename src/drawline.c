/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:33:25 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/07 23:50:24 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_xline(t_map_info map_info_start, t_map_info map_info_end, double dist, t_data img)
{
	int				x;
	int				color;
	double			percent;
	t_color_elems	color_diff;

	color_diff = get_col_diff(map_info_start.color, map_info_end.color);
	x = map_info_start.x + 1;
	while (map_info_start.x <= x && x <= map_info_end.x)
	{
		percent = get_dist(x, map_info_start.x, map_info_start.y, map_info_start.y) / dist;
		color = add_col(map_info_start.color, color_diff, percent);
		my_mlx_pixel_put(&img, x, map_info_start.y, color);
		x++;
	}
}

void	draw_yline(t_map_info map_info_start, t_map_info map_info_end, double dist, t_data img)
{
	int				y;
	int				color;
	double			percent;
	t_color_elems	color_diff;

	color_diff = get_col_diff(map_info_start.color, map_info_end.color);
	y = map_info_start.y + 1;
	while (map_info_start.y <= y && y <= map_info_end.y)
	{
		percent = get_dist(map_info_start.x, map_info_start.x, y, map_info_start.y) / dist;
		color = add_col(map_info_start.color, color_diff, percent);
		my_mlx_pixel_put(&img, map_info_start.x, y, color);
		y++;
	}
}

void	drawline_by_x(t_map_info map_info_start, t_map_info map_info_end, t_line_params line_params, double dist, t_data img)
{
	int				x;
	int				y;
	int				color;
	double			percent;
	t_color_elems	color_diff;

	x = map_info_start.x + 1;
	color_diff = get_col_diff(map_info_start.color, map_info_end.color);
	while (map_info_start.x <= x && x <= map_info_end.x)
	{
		y = get_y(x, line_params);
		percent = get_dist(x, map_info_start.x, y, map_info_start.y) / dist;
		color = add_col(map_info_start.color, color_diff, percent);
		my_mlx_pixel_put(&img, x, y, color);
		x++;
	}
}

void	drawline_by_y(t_map_info map_info_start, t_map_info map_info_end, t_line_params line_params, double dist, t_data img)
{
	int				x;
	int				y;
	int				color;
	double			percent;
	t_color_elems	color_diff;

	x = 0;
	y = map_info_start.y + 1;
	color_diff = get_col_diff(map_info_start.color, map_info_end.color);
	while (map_info_start.y <= y && y <= map_info_end.y)
	{
		x = get_x(y, line_params);
		percent = get_dist(x, map_info_start.x, y, map_info_start.y) / dist;
		color = add_col(map_info_start.color, color_diff, percent);
		my_mlx_pixel_put(&img, x, y, color);
		y++;
	}
}

void	drawline(t_map_info map_info1, t_map_info map_info2, t_map_size map_size, t_data img)
{
	t_line_params	line_params;
	double			dist;

	map_info1.x = 900.0 + (400.0 / map_size.x_length) * map_info1.x;
	map_info1.y = 400.0 + (400.0 / map_size.x_length) * map_info1.y;
	map_info2.x = 900.0 + (400.0 / map_size.x_length) * map_info2.x;
	map_info2.y = 400.0 + (400.0 / map_size.x_length) * map_info2.y;
	line_params = get_params(map_info1.x, map_info2.x, map_info1.y, map_info2.y);
	dist = get_dist(map_info1.x, map_info2.x, map_info1.y, map_info2.y);

	if (map_info1.x == map_info2.x)
	{
		if (map_info1.y < map_info2.y)
			draw_yline(map_info1, map_info2, dist, img);
		else
			draw_yline(map_info2, map_info1, dist, img);
	}
	else if (map_info1.x < map_info2.x)
		drawline_by_x(map_info1, map_info2, line_params, dist, img);
	else
		drawline_by_x(map_info2, map_info1, line_params, dist, img);
	if (map_info1.y == map_info2.y)
	{
		if (map_info1.x < map_info2.x)
			draw_xline(map_info1, map_info2, dist, img);
		else
			draw_xline(map_info2, map_info1, dist, img);
	}
	else if (map_info1.y < map_info2.y)
		drawline_by_y(map_info1, map_info2, line_params, dist, img);
	else
		drawline_by_y(map_info2, map_info1, line_params, dist, img);
}
