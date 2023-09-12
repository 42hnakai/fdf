/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:37:15 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/12 22:52:23 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>

// information of map
typedef struct s_map_info
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_map_info;

// SIZE OF MAP
typedef struct s_map_size
{
	int			x_length;
	int			y_length;
}				t_map_size;

// INFORMATION OF LINE
typedef struct s_line_params
{
	double		slope;
	double		intercept;
}				t_line_params;

// X VECTOR
typedef struct s_x_vector
{
	double		new_x;
	double		new_y;
}				t_x_vector;

// Y VECTOR
typedef struct s_y_vector
{
	double		new_x;
	double		new_y;
}				t_y_vector;

// about minilibx
typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_color_elems
{
	int			t;
	int			r;
	int			g;
	int			b;
}				t_color_elems;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_data		img;
	t_map_info	**map_info;
}				t_vars;

//=CHECK_ERROR.c===============================================================
int				check_valid_map(char *file_name);
int				check_z_color(char **elems_ary);
int				check_valid_size(char **elems_ary, int flag);
int				check_file(int argc, char *file_name);
//=CHECK_ERROR_UTILS.c=========================================================
int				check_z(char *z);
int				check_color(char *color);
//=COLOR.c=====================================================================
t_color_elems	get_col_elem(int color);
t_color_elems	get_col_diff(int color1, int color2);
int				add_col(int color, t_color_elems color_diff, double percent);
//=GET_MAP_INFO.c==============================================================
t_map_info		**get_map_info(t_map_info **map_info, t_map_size map_size,
					char *file_name);
void			get_elems(t_map_info **map_info, char **elems_ary, int y_axis);
t_map_info		**malloc_map_info(t_map_size map_size);
void			get_xy(t_map_info **map_info, t_map_size map_size);
//=GET_MAP_INFO_UTILS.c========================================================
void			get_z(t_map_info **map_info, char *z_ary, int y, int x);
void			get_color(t_map_info **map_info, char *color_ary, int y_axis,
					int x_axis);
int				get_x_length(char **info_by_space);
t_map_size		get_map_size(char *file_name);
int				hex_to_bin(char *hex);
//=GET_MAP_INFO_UTILS2.c=======================================================
char			**get_elems_ary(char *line);
//=DROWLINE.c==================================================================
void			draw_xline(t_map_info map_info_start, t_map_info map_info_end,
					t_data img);
void			draw_yline(t_map_info map_info_start, t_map_info map_info_end,
					t_data img);
void			drawline_by_x(t_map_info map_info_start,
					t_map_info map_info_end, t_line_params line_params,
					t_data img);
void			drawline_by_y(t_map_info map_info_start,
					t_map_info map_info_end, t_line_params line_params,
					t_data img);
void			drawline(t_map_info map_info1, t_map_info map_info2,
					t_map_size map_size, t_data img);
//=DROWLINE_UTILS.c============================================================
void			help_drawline(t_map_info start, t_map_info end,
					t_line_params line_params, t_data img);
t_line_params	get_params(double x1, double x2, double y1, double y2);
int				get_x(int y, t_line_params line_params);
int				get_y(int x, t_line_params line_params);
double			get_dist(double x1, double x2, double y1, double y2);
//=GET MAP VECTOR==============================================================
t_map_info		**get_map_vector(t_map_info **map_info, t_map_size map_size);
//=UTILS.c=====================================================================
void			free_double_n(t_map_info **map_info, int i);
void			free_double(void **str);
void			check_fd(int fd);
void			check_close(int fd);
t_map_info		change_scale(t_map_info map_info, t_map_size map_size);
//=MAIN FILE===================================================================
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
//=CLOSE_TERMINAL.c============================================================
int				esc_close(int keycode, t_vars *vars);
int				x_close(t_vars *vars);

#endif