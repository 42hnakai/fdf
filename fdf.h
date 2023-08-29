/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:37:15 by hnakai            #+#    #+#             */
/*   Updated: 2023/08/29 23:45:54 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include <stdio.h>
#include <fcntl.h>
#include <mlx.h>
#include <math.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "mlx/mlx.h"

// information of map
typedef struct s_map_info
{
	double x;
	double y;
	double z;
	double color;
} t_map_info;

// SIZE OF MAP
typedef struct s_map_size
{
	int x_length;
	int y_length;
} t_map_size;

// INFORMATION OF LINE
typedef struct s_line_params
{
	double slope;
	double intercept;
} t_line_params;

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
t_map_info **get_map_info(t_map_info **map_info, t_map_size map_size);
t_map_info **malloc_map_info(t_map_size map_size);
void get_xy(t_map_info **map_info, t_map_size map_size);
t_map_info **get_z(t_map_info **map_info, char *line, int y_axis);
int get_x_length(char *line);
t_map_size get_map_size();

// DROWLINE
void drowline(double x1, double x2, double y1, double y2, t_data img);

// GET MAP VECTOR
t_map_info **get_map_vector(t_map_info **map_info, t_map_size map_size);

// MAIN FILE
void my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif