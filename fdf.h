/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:37:15 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/02 13:08:48 by hnakai           ###   ########.fr       */
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
	int color;
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

// X VECTOR
typedef struct s_x_vector
{
	double new_x;
	double new_y;
} t_x_vector;

// Y VECTOR
typedef struct s_y_vector
{
	double new_x;
	double new_y;
} t_y_vector;

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
t_map_info **get_map_info(t_map_info **map_info, t_map_size map_size, char *file_name);
t_map_info **malloc_map_info(t_map_size map_size);
void get_xy(t_map_info **map_info, t_map_size map_size);
t_map_info **get_z(t_map_info **map_info, char *line, int y_axis);
int get_x_length(char *line);
t_map_size get_map_size(char *file_name);

// DROWLINE
void drowline(double x1, double x2, double y1, double y2, t_data img);

// GET MAP VECTOR
t_map_info **get_map_vector(t_map_info **map_info, t_map_size map_size);

// MAIN FILE
void my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif