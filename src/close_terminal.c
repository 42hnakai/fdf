/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_terminal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:00:53 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/12 20:48:57 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	esc_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free_double((void **)vars->map_info);
		exit(0);
	}
	return (0);
}

int	x_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free_double((void **)vars->map_info);
	exit(0);
}
