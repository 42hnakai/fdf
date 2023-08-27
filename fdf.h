/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:37:15 by hnakai            #+#    #+#             */
/*   Updated: 2023/08/27 18:00:15 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "mlx/mlx.h"

// information of map
typedef struct s_map_info
{
	int x_axis;
	int y_axis;
	int z_axis;
	int color;
} t_map_info;

// SIZE OF MAP
typedef struct s_map_size
{
	int x_length;
	int y_length;
} t_map_size;

// about minilibx
typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

// GET_MAP_INFO FILE
t_map_info **get_map_info(t_map_info **map_info);
t_map_info **malloc_map_info(t_map_size map_size);
t_map_info **get_z_axis(t_map_info **map_info, char *line, int y_axis);
int get_x_length(char *line);
t_map_size get_map_size();

// MAIN FILE
void my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif