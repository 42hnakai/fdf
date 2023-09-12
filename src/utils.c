/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:59:13 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/12 22:46:44 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_double_n(t_map_info **map_info, int i)
{
	while (i > 0)
	{
		free(map_info[i - 1]);
		i--;
	}
	free(map_info);
}

void	free_double(void **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	check_fd(int fd)
{
	if (fd == -1)
	{
		ft_printf("[ERROR!] missing to open file!\n");
		exit(1);
	}
}

void	check_close(int fd)
{
	if (close(fd) == -1)
	{
		ft_printf("[ERROR!] missing to close file!\n");
		exit(1);
	}
}

t_map_info	change_scale(t_map_info map_info, t_map_size map_size)
{
	map_info.x = 900.0 + (400.0 / map_size.x_length) * map_info.x;
	map_info.y = 400.0 + (400.0 / map_size.x_length) * map_info.y;
	return (map_info);
}
