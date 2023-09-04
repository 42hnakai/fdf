/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:38:19 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/04 22:11:27 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map_info	**get_map_vector(t_map_info **map_info, t_map_size map_size)
{
	int			x;
	int			y;
	t_x_vector	x_vector;
	t_y_vector	y_vector;

	x = 0;
	y = 0;
	x_vector.new_x = map_info[0][1].x * cos(30 * M_PI / 180);
	x_vector.new_y = map_info[0][1].x * sin(30 * M_PI / 180);
	y_vector.new_x = -map_info[1][0].y * cos(30 * M_PI / 180);
	y_vector.new_y = map_info[1][0].y * sin(30 * M_PI / 180);
	while (y < map_size.y_length)
	{
		x = 0;
		while (x < map_size.x_length)
		{
			map_info[y][x].x = x_vector.new_x * x + y_vector.new_x * y;
			map_info[y][x].y = x_vector.new_y * x + y_vector.new_y * y - map_info[y][x].z / 3;
			x++;
		}
		y++;
	}
	return (map_info);
}
