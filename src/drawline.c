/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:33:25 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/13 02:34:00 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_xline(t_map_info start, t_map_info end, t_data img)
{
	int				x;
	int				color;
	double			percent;
	t_color_elems	color_diff;

	color_diff = get_col_diff(start.color, end.color);
	x = start.x + 1;
	while (start.x <= x && x <= end.x)
	{
		percent = get_dist(x, start.x, start.y, start.y) / get_dist(start.x,
				end.x, start.y, end.y);
		color = add_col(start.color, color_diff, percent);
		my_mlx_pixel_put(&img, x, start.y, color);
		x++;
	}
}

void	draw_yline(t_map_info start, t_map_info end, t_data img)
{
	int				y;
	int				color;
	double			percent;
	t_color_elems	color_diff;

;	color_diff = get_col_diff(start.color, end.color);
	y = start.y + 1;
	while (start.y <= y && y <= end.y)
	{
		percent = get_dist(start.x, start.x, y, start.y) / get_dist(start.x,
				end.x, start.y, end.y);
		color = add_col(start.color, color_diff, percent);
		my_mlx_pixel_put(&img, start.x, y, color);
		y++;
	}
}

void	drawline_by_x(t_map_info start, t_map_info end,
		t_line_params line_params, t_data img)
{
	int				x;
	int				y;
	int				color;
	double			percent;
	t_color_elems	color_diff;

	x = start.x + 1;
	color_diff = get_col_diff(start.color, end.color);
	while (start.x <= (double)x && (double)x <= end.x)
	{
		y = get_y(x, line_params);
		percent = get_dist(x, start.x, y, start.y) / get_dist(start.x, end.x,
				start.y, end.y);
		color = add_col(start.color, color_diff, percent);
		my_mlx_pixel_put(&img, x, y, color);
		x++;
	}
}

void	drawline_by_y(t_map_info start, t_map_info end,
		t_line_params line_params, t_data img)
{
	int				x;
	int				y;
	int				color;
	double			percent;
	t_color_elems	color_diff;

	x = 0;
	y = start.y + 1;
	color_diff = get_col_diff(start.color, end.color);
	while (start.y <= (double)y && (double)y <= end.y)
	{
		x = get_x(y, line_params);
		percent = get_dist(x, start.x, y, start.y) / get_dist(start.x, end.x,
				start.y, end.y);
		color = add_col(start.color, color_diff, percent);
		my_mlx_pixel_put(&img, x, y, color);
		y++;
	}
}

void	drawline(t_map_info start, t_map_info end, t_map_size map_size,
		t_data img)
{
	t_line_params	line_params;

	start = change_scale(start, map_size);
	end = change_scale(end, map_size);
	line_params = get_params(start.x, end.x, start.y, end.y);
	help_drawline(start, end, line_params, img);
}
