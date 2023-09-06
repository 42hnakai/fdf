/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:19:04 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/06 22:05:19 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void get_x_y(t_map_info **map_info, t_map_size map_size)
{
	int x;
	int y;

	y = 0;
	while (y < map_size.y_length)
	{
		x = 0;
		while (x < map_size.x_length)
		{
			map_info[y][x].x = x;
			map_info[y][x].y = y;
			x++;
		}
		y++;
	}
}

int hex_to_bin(char *hex)
{
	int bin;
	int len;
	int i;

	i = 0;
	len = ft_strlen(hex);
	bin = 0;
	while (hex[(len - 1) - i] != 'x')
	{
		if ('0' <= hex[(len - 1) - i] && hex[(len - 1) - i] <= '9')
		{
			bin += pow(16, i) * (hex[(len - 1) - i] - '0');
		}
		else if ('A' <= hex[(len - 1) - i] && hex[(len - 1) - i] <= 'F')
		{
			bin += pow(16, i) * (hex[(len - 1) - i] - 55);
		}
		i++;
	}
	return (bin);
}

int get_x_length(char **info_by_space)
{
	int i;
	int x_length;

	i = 0;
	while (info_by_space[i] != NULL)
		i++;
	x_length = i;
	return (x_length); // EXCEPT NEWLINE
}

// MALLOC MAP_INFO
t_map_info **malloc_map_info(t_map_size map_size)
{
	int i;
	t_map_info **map_info;

	i = 0;
	map_info = malloc(sizeof(t_map_info *) * (map_size.y_length + 1));
	if (map_info == NULL)
		return (NULL);
	while (i < map_size.y_length)
	{
		map_info[i] = malloc(sizeof(t_map_info) * (map_size.x_length + 1));
		if (map_info[i] == NULL)
		{
			free_double(map_info, i);
			return (NULL);
		}
		i++;
	}
	return (map_info);
}

// GET MAP SIZE(X_LENGTH, Y_LENGTH)
t_map_size get_map_size(char *file_name)
{
	int fd;
	t_map_size map_size;
	char *line;
	char **elems_ary;

	map_size.y_length = 0;
	fd = open(file_name, O_RDONLY);
	check_fd(fd);
	if ((line = get_next_line(fd)) != NULL)
	{
		line = ft_strtrim(line, "\n");
		elems_ary = ft_split(line, ' ');
		map_size.x_length = get_x_length(elems_ary);
		map_size.y_length++;
		free(line);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		free(line);
		map_size.y_length++;
	}
	check_close(fd);
	return (map_size);
}

void get_elems(t_map_info **map_info, char **elems_ary, int y_axis)
{
	int x_axis;
	char **z_color_ary;
	char *z_ary;
	char *color_ary;

	x_axis = 0;
	while (elems_ary[x_axis] != NULL)
	{
		z_color_ary = ft_split(elems_ary[x_axis], ',');
		z_ary = z_color_ary[0];
		color_ary = z_color_ary[1];
		get_z(map_info, z_ary, y_axis, x_axis);
		get_color(map_info, color_ary, y_axis, x_axis);
		x_axis++;
	}
}

void get_color(t_map_info **map_info, char *color_ary, int y_axis, int x_axis)
{

	if (color_ary != NULL)
		map_info[y_axis][x_axis].color = hex_to_bin(color_ary);
	else
		map_info[y_axis][x_axis].color = hex_to_bin("0xFFFFFF");
}

void get_z(t_map_info **map_info, char *z_ary, int y_axis, int x_axis)
{
	map_info[y_axis][x_axis].z = ft_atoi(z_ary);
}

t_map_info **get_map_info(t_map_info **map_info, t_map_size map_size, char *file_name)
{
	int fd;
	int y_axis;
	char *line;
	char **elems_ary;

	y_axis = 0;
	fd = open(file_name, O_RDONLY);
	check_fd(fd);
	get_x_y(map_info, map_size);
	while ((line = get_next_line(fd)) != NULL)
	{
		line = ft_strtrim(line, "\n");
		elems_ary = ft_split(line, ' ');
		get_elems(map_info, elems_ary, y_axis);
		free(line);
		y_axis++;
	}
	check_close(fd);
	return (map_info);
}
