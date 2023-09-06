/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:37:15 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/06 22:40:58 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include <stdio.h>
#include <fcntl.h>
#include <mlx.h>
#include <math.h>
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include "../mlx/mlx.h"


#include <time.h>
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

typedef struct s_color_elem
{
	int t;
	int r;
	int g;
	int b;
} t_color_elem;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	t_data	img;
}	t_vars;

// CHECK_ERROR.c
int check_file(int argc, char *file_name);
int check_z_color(char **info_by_space);
int check_color(char *color);
int check_z(char *z);
int check_valid_map(char *file_name);


t_map_info **get_map_info(t_map_info **map_info, t_map_size map_size, char *file_name);
t_map_info **malloc_map_info(t_map_size map_size);
void get_xy(t_map_info **map_info, t_map_size map_size);
int get_x_length(char **info_by_space);
t_map_size get_map_size(char *file_name);

// DROWLINE.c
void drawline(t_map_info map_info1, t_map_info map_info2, t_map_size map_size, t_data img);

// GET MAP VECTOR
t_map_info **get_map_vector(t_map_info **map_info, t_map_size map_size);

// DROWLINE.c
t_line_params get_params(double x1, double x2, double y1, double y2);
double get_dist(double x1, double x2, double y1, double y2);

// GET_MAP_INFO.c
void get_x_y(t_map_info **map_info, t_map_size map_size);
int hex_to_bin(char *hex);
void get_elems(t_map_info **map_info, char **elems_ary, int y_axis);
void get_color(t_map_info **map_info, char *color_ary, int y_axis, int x_axis);
void get_z(t_map_info **map_info, char *z_ary, int y_axis, int x_axis);
t_map_info **malloc_map_info(t_map_size map_size);
t_map_size get_map_size(char *file_name);
t_map_info **get_map_info(t_map_info **map_info, t_map_size map_size, char *file_name);

// COLOR.c
t_color_elem get_col_elem(int color);
t_color_elem get_col_diff(t_color_elem color_elem1, t_color_elem color_elem2);
int add_col(t_color_elem color_diff, double percent);

// UTILS.c
void	free_double(t_map_info **map_info, int i);
int		display_error(char *massage);
void	check_fd(int fd);
void	check_close(int fd);

// MAIN FILE
void my_mlx_pixel_put(t_data *data, int x, int y, int color);

void start_timer(clock_t *start);
void end_timer(clock_t start, const char *func_name);
#endif