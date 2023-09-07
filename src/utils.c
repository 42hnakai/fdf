/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:59:13 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/08 00:30:27 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_double(t_map_info **map_info, int i)
{
	while (i > 0)
	{
		free(map_info[i - 1]);
		i--;
	}
	free(map_info);
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

int	esc_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	x_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}
