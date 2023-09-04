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

char *a;

"\n"