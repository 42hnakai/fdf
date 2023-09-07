void drawline(t_map_info map_info1, t_map_info map_info2, t_map_size map_size, t_data img)
{
	int x;
	int y;
	int color;
	double percent;
	t_color_elem color_elem1;
	t_color_elem color_elem2;
	t_color_elem color_diff;
	map_info1.x = 900.0 + (400.0 / map_size.x_length) * map_info1.x;
	map_info1.y = 400.0 + (400.0 / map_size.x_length) * map_info1.y;
	map_info2.x = 900.0 + (400.0 / map_size.x_length) * map_info2.x;
	map_info2.y = 400.0 + (400.0 / map_size.x_length) * map_info2.y;
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
		color_diff = get_col_diff(color_elem1, color_elem2);
		y = map_info1.y + 1;
		while (map_info1.y <= y && y <= map_info2.y)
		{
			my_mlx_pixel_put(&img, map_info1.x, y, 0xFFFFFF);
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
			my_mlx_pixel_put(&img, x, map_info1.y, 0xFFFFFF);
			x++;
		}
	}
	else
	{
		line_params = get_params(map_info1.x, map_info2.x, map_info1.y, map_info2.y);
		if (map_info2.x < map_info1.x)
		{
			color_diff = get_col_diff(color_elem2, color_elem1);
			x = map_info2.x + 1;
			while (map_info2.x <= x && x <= map_info1.x)
			{
				y = get_y(x, line_params);
				percent = get_dist(x, map_info2.x, y, map_info2.y) / get_dist(map_info1.x, map_info2.x, map_info1.y, map_info2.y);
				color = add_col(color_elem2, color_diff, percent);
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
				color = add_col(color_elem1, color_diff, percent);
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
				color = add_col(color_elem2, color_diff, percent);
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
				color = add_col(color_elem1, color_diff, percent);
				my_mlx_pixel_put(&img, x, y, color);
				y++;
			}
		}
	}
}

#include "src/fdf.h"
