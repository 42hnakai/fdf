/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 00:03:50 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/14 17:44:28 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_color(t_map_info **map_info, char *color_ary, int y, int x)
{
	if (color_ary != NULL)
		map_info[y][x].color = hex_to_bin(color_ary);
	else
		map_info[y][x].color = hex_to_bin("0xFFFFFF");
}

void	get_z(t_map_info **map_info, char *z_ary, int y, int x)
{
	map_info[y][x].z = ft_atoi(z_ary);
}

int	hex_to_bin(char *hex)
{
	int	bin;
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(hex);
	bin = 0;
	while (hex[(len - 1) - i] != 'x')
	{
		if ('0' <= hex[(len - 1) - i] && hex[(len - 1) - i] <= '9')
		{
			bin += pow(16, i) * (hex[(len - 1) - i] - '0');
		}
		else if ('A' <= hex[(len - 1) - i] && hex[(len - 1) - i] <= 'F')
		{
			bin += pow(16, i) * (hex[(len - 1) - i] - 'A' + 10);
		}
		else if ('a' <= hex[(len - 1) - i] && hex[(len - 1) - i] <= 'f')
		{
			bin += pow(16, i) * (hex[(len - 1) - i] - 'a' + 10);
		}
		i++;
	}
	return (bin);
}

int	get_x_length(char **info_by_space)
{
	int	i;
	int	x_length;

	i = 0;
	while (info_by_space[i] != NULL)
		i++;
	x_length = i;
	return (x_length);
}

// MALLOC MAP_INFO
t_map_info	**malloc_map_info(t_map_size map_size)
{
	int			i;
	t_map_info	**map_info;

	i = 0;
	map_info = malloc(sizeof(t_map_info *) * (map_size.y_length + 1));
	if (map_info == NULL)
	{
		ft_printf("[ERROR!] fail malloc\n");
		exit(1);
	}
	while (i < map_size.y_length)
	{
		map_info[i] = malloc(sizeof(t_map_info) * (map_size.x_length + 1));
		if (map_info[i] == NULL)
		{
			free_double_n(map_info, i);
			ft_printf("[ERROR!] fail malloc\n");
			exit(1);
		}
		i++;
	}
	map_info[i] = NULL;
	return (map_info);
}
