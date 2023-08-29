/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:38:19 by hnakai            #+#    #+#             */
/*   Updated: 2023/08/29 23:51:19 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map_info **get_map_vector(t_map_info **map_info, t_map_size map_size)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < map_size.y_length)
	{
		x = 0;
		while (x < map_size.x_length)
		{
			map_info[y][x].x = map_info[y][x].x * cos(30 * M_PI / 180);
			map_info[y][x].y = map_info[y][x].y * sin(30 * M_PI / 180);
			printf("x : %f, y : %f\n",map_info[y][x].x,map_info[y][x].y);
			x++;
		}
		y++;
	}
	return (map_info);
}