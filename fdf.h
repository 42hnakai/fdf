/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:37:15 by hnakai            #+#    #+#             */
/*   Updated: 2023/08/26 19:49:22 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "mlx/mlx.h"

//information of map
typedef struct s_map_info
{
	int x_axis;
	int y_axis;
	int z_axis;
	int color;
} t_map_info;

// about minilibx
typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

//GET_MAP_INFO FILE
t_map_info **get_map_info();
t_map_info **get_z_axis(t_map_info ***map_info, char *line, int y_axis);

//MAIN FILE
void my_mlx_pixel_put(t_data *data, int x, int y, int color);

# endif