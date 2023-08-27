/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:19:04 by hnakai            #+#    #+#             */
/*   Updated: 2023/08/27 18:00:41 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map_info **get_z_axis(t_map_info **map_info, char *line, int y_axis)
{
	int i;
	char **splits;

	i = 0;
	splits = ft_split(line, ' ');
	while (splits[i] != NULL)
	{
		map_info[y_axis][i].z_axis = ft_atoi(&splits[i][0]);
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
	while (splits[x_length] != NULL)
		x_length++;
	return (x_length - 1); // EXCEPT NEWLINE
}

// MALLOC MAP_INFO
t_map_info **malloc_map_info(t_map_size map_size)
{
	int i;
	t_map_info **map_info;

	i = 0;
	map_info = malloc(sizeof(t_map_info *) * (map_size.y_length + 1));
	while (i < map_size.y_length)
	{
		map_info[i] = malloc(sizeof(t_map_info) * (map_size.x_length + 1));
		i++;
	}
	return (map_info);
}

// GET MAP SIZE(X_LENGTH, Y_LENGTH)
t_map_size get_map_size()
{
	int fd;
	t_map_size map_size;
	char *line;

	map_size.y_length = 0;
	fd = open("10-2.fdf", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
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
		perror("Error closing file");
		exit(1);
	}
	return (map_size);
}

t_map_info **get_map_info(t_map_info **map_info)
{
	int fd;
	int y_axis;
	char *line;

	y_axis = 0;
	// MALLOC MAP_INFO
	fd = open("10-2.fdf", O_RDONLY);
	// GET EVERY LINE TO LINE
	while ((line = get_next_line(fd)) != NULL)
	{
		get_z_axis(map_info, line, y_axis);
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