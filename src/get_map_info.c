/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:19:04 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/12 22:41:45 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_x_y(t_map_info **map_info, t_map_size map_size)
{
	int	x;
	int	y;

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

// GET MAP SIZE(X_LENGTH, Y_LENGTH)
t_map_size	get_map_size(char *file_name)
{
	int			fd;
	t_map_size	map_size;
	char		*line;
	char		**elems_ary;

	map_size.y_length = 0;
	fd = open(file_name, O_RDONLY);
	check_fd(fd);
	line = get_next_line(fd);
	if (line != NULL)
	{
		elems_ary = get_elems_ary(line);
		map_size.x_length = get_x_length(elems_ary);
		map_size.y_length++;
		free_double((void **)elems_ary);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		map_size.y_length++;
		free(line);
		line = get_next_line(fd);
	}
	check_close(fd);
	return (map_size);
}

void	get_elems(t_map_info **map_info, char **elems_ary, int y_axis)
{
	int		x_axis;
	char	**z_color_ary;
	char	*z_ary;
	char	*color_ary;

	x_axis = 0;
	while (elems_ary[x_axis] != NULL)
	{
		z_color_ary = ft_split(elems_ary[x_axis], ',');
		z_ary = z_color_ary[0];
		color_ary = z_color_ary[1];
		get_z(map_info, z_ary, y_axis, x_axis);
		get_color(map_info, color_ary, y_axis, x_axis);
		free_double((void **)z_color_ary);
		x_axis++;
	}
}

t_map_info	**get_map_info(t_map_info **map_info, t_map_size map_size,
		char *file_name)
{
	int		fd;
	int		y_axis;
	char	*line;
	char	*line_no_nl;
	char	**elems_ary;

	y_axis = 0;
	fd = open(file_name, O_RDONLY);
	check_fd(fd);
	get_x_y(map_info, map_size);
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_no_nl = ft_strtrim(line, "\n");
		free(line);
		elems_ary = ft_split(line_no_nl, ' ');
		free(line_no_nl);
		get_elems(map_info, elems_ary, y_axis);
		y_axis++;
		free_double((void **)elems_ary);
		line = get_next_line(fd);
	}
	check_close(fd);
	return (map_info);
}
