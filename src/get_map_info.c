/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:19:04 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/05 18:48:27 by hnakai           ###   ########.fr       */
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

t_map_info **get_z(t_map_info **map_info, char *line, int y_axis)
{
	int i;
	char **info;
	char **z;

	i = 0;
	info = ft_split(line, ' ');
	while (info[i] != NULL)
	{
		z = ft_split(info[i], ',');
		map_info[y_axis][i].z = ft_atoi(z[0]);
		i++;
	}
	return (map_info);
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

t_map_info **get_color(t_map_info **map_info, char *line, int y_axis)
{
	int i;
	char **info;
	char **color;

	i = 0;
	info = ft_split(line, ' ');
	while (info[i] != NULL)
	{
		color = ft_split(info[i], ',');
		if (color[1] != NULL)
			map_info[y_axis][i].color = hex_to_bin(color[1]);
		else
			map_info[y_axis][i].color = hex_to_bin("0xFFFFFF");
		i++;
	}
	return (map_info);
}

int get_x_length(char *line)
{
	int x_length;
	char **splits;

	x_length = 0;
	splits = ft_split(line, ' ');
	while (splits[x_length] != NULL && ft_strncmp(splits[x_length], "\n", 1) != 0)
		x_length++;
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

	map_size.y_length = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		exit(1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		map_size.x_length = get_x_length(line);
		free(line);
		map_size.y_length++;
	}
	if (close(fd) == -1)
	{
		printf("Error closing file");
		exit(1);
	}
	return (map_size);
}

t_map_info **get_map_info(t_map_info **map_info, t_map_size map_size, char *file_name)
{
	int fd;
	int y_axis;
	char *line;

	y_axis = 0;
	// MALLOC MAP_INFO
	fd = open(file_name, O_RDONLY);
	// GET EVERY LINE TO LINE
	get_x_y(map_info, map_size);
	while ((line = get_next_line(fd)) != NULL)
	{
		line = ft_strtrim(line, "\n");
		get_z(map_info, line, y_axis);
		get_color(map_info, line, y_axis);
		free(line);
		y_axis++;
	}
	// CLOSE FD
	if (close(fd) == -1)
	{
		perror("Error closing file");
		exit(1);
	}
	return (map_info);
}
