/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:19:04 by hnakai            #+#    #+#             */
/*   Updated: 2023/08/26 21:11:52 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map_info **get_z_axis(t_map_info ***map_info, char *line, int y_axis)
{
	int i;
	char **splits;

	i = 0;
	splits = ft_split(line, ' ');
	while (splits[i] != NULL)
	{
		printf("PASS\n");
		map_info[y_axis][i]->z_axis = ft_atoi(&splits[i][0]);
		i++;
	}
	map_info[y_axis][i] = NULL;
	return (*map_info);
}

int get_x_length(char *line)
{
	int x_length;
	char **splits;

	x_length = 0;
	splits = ft_split(line, ' ');
	while (splits[x_length] != NULL)
		x_length++;
	return (x_length - 1); //EXCEPT NEWLINE
}

t_map_info **malloc_map_info(int fd)
{
	char *line;
	int x_length;
	int y_length;
	int i;
	t_map_info **map_info;

	i = 0;
	y_length = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		x_length = get_x_length(line);
		free(line);
		y_length++;
	}
	printf("x_length : %d\n",x_length);
	printf("y_length : %d\n",y_length);
	map_info = (t_map_info **)malloc(sizeof(int *) * (y_length + 1));
	while (i < y_length)
	{
		map_info[i] = malloc(sizeof(int) * (x_length + 1));
		i++;
	}
	return (map_info);
}

t_map_info **get_map_info()
{
	int fd;
	int y_axis;
	char *line;
	t_map_info **map_info;

	y_axis = 0;
	// OPEN FILE "10-2.fdf"
	fd = open("10-2.fdf", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(1);
	}
	// MALLOC MAP_INFO
	map_info = malloc_map_info(fd);
	if (close(fd) == -1)
	{
		perror("Error closing file");
		exit(1);
	}
	fd = open("10-2.fdf", O_RDONLY);
	// GET EVERY LINE TO LINE
	while ((line = get_next_line(fd)) != NULL)
	{
		get_z_axis(&map_info, line, y_axis);
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