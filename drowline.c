/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drowline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:33:25 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/04 23:50:11 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// WANT TO CHANGE FUNC NAME TO "GET_LINE_PARAMS"
t_line_params make_line_wq(double x1, double x2, double y1, double y2)
{
	double diff_x;
	double diff_y;
	t_line_params line_params;

	diff_x = x2 - x1;
	diff_y = y2 - y1;
	line_params.slope = diff_y / diff_x;
	line_params.intercept = y1 - line_params.slope * x1;
	return (line_params);
}

int get_x(int y, t_line_params line_params)
{
	return ((int)((y - line_params.intercept) / line_params.slope));
}

int get_y(int x, t_line_params line_params)
{
	return ((int)(line_params.slope * x + line_params.intercept));
}

void ft_swap(double *a, double *b)
{
	double c;
	c = *a;
	*a = *b;
	*b = c;
}
// GET DIST
double get_dist(double x1, double x2, double y1, double y2)
{
	double x_diff;
	double y_diff;
	double dist;
	x_diff = x2 - x1;
	y_diff = y2 - y1;
	dist = sqrt(x_diff * x_diff + y_diff * y_diff);
	return (dist);
}

void drawline(t_map_info map_info1, t_map_info map_info2, t_data img)
{
	int x;
	int y;
	int color;
	double percent;
	t_color_elem color_elem1;
	t_color_elem color_elem2;
	t_color_elem color_diff;
	map_info1.x = 500 + 10 * map_info1.x;
	map_info1.y = 500 + 10 * map_info1.y;
	map_info2.x = 500 + 10 * map_info2.x;
	map_info2.y = 500 + 10 * map_info2.y;
	t_line_params line_params;
	// SPLIT T,R,B,G
	color_elem1 = get_col_elem(map_info1.color);
	color_elem2 = get_col_elem(map_info2.color);
	if (map_info1.x == map_info2.x)
	{
		if (map_info2.y < map_info1.y)
		{
			ft_swap(&map_info1.y, &map_info2.y);
		}
		y = map_info1.y + 1;
		while (map_info1.y <= y && y <= map_info2.y)
		{
			my_mlx_pixel_put(&img, map_info1.x, y, 0x00FFFF);
			y++;
		}
	}
	else if (map_info1.y == map_info2.y)
	{
		if (map_info2.x < map_info1.x)
		{
			ft_swap(&map_info1.x, &map_info2.x);
		}
		x = map_info1.x + 1;
		while (map_info1.x <= x && x <= map_info2.x)
		{
			my_mlx_pixel_put(&img, x, map_info1.y, 0x00FF0000);
			x++;
		}
	}
	else
	{
		line_params = make_line_wq(map_info1.x, map_info2.x, map_info1.y, map_info2.y);
		if (map_info2.x < map_info1.x)
		{
			color_diff = get_col_diff(color_elem2, color_elem1);
			x = map_info2.x + 1;
			while (map_info2.x <= x && x <= map_info1.x)
			{
				y = get_y(x, line_params);
				percent = get_dist(x, map_info2.x, y, map_info2.y) / get_dist(map_info1.x, map_info2.x, map_info1.y, map_info2.y);
				color = map_info2.color + add_col(color_diff, percent);
				my_mlx_pixel_put(&img, x, y, color);
				x++;
			}
		}
		else
		{
			color_diff = get_col_diff(color_elem1, color_elem2);
			x = map_info1.x + 1;
			while (map_info1.x <= x && x <= map_info2.x)
			{
				y = get_y(x, line_params);
				percent = get_dist(x, map_info1.x, y, map_info1.y) / get_dist(map_info1.x, map_info2.x, map_info1.y, map_info2.y);
				color = map_info1.color + add_col(color_diff, percent);
				my_mlx_pixel_put(&img, x, y, color);
				x++;
			}
		}
		if (map_info2.y < map_info1.y)
		{
			color_diff = get_col_diff(color_elem2, color_elem1);
			y = map_info2.y + 1;
			while (map_info2.y <= y && y <= map_info1.y)
			{
				x = get_x(y, line_params);
				percent = get_dist(x, map_info2.x, y, map_info2.y) / get_dist(map_info1.x, map_info2.x, map_info1.y, map_info2.y);
				color = map_info2.color + add_col(color_diff, percent);
				my_mlx_pixel_put(&img, x, y, color);
				y++;
			}
		}
		else
		{
			color_diff = get_col_diff(color_elem1, color_elem2);
			y = map_info1.y + 1;
			while (map_info1.y <= y && y <= map_info2.y)
			{
				x = get_x(y, line_params);
				percent = get_dist(x, map_info1.x, y, map_info1.y) / get_dist(map_info1.x, map_info2.x, map_info1.y, map_info2.y);
				color = map_info1.color + add_col(color_diff, percent);
				my_mlx_pixel_put(&img, x, y, color);
				y++;
			}
		}
	}
}
